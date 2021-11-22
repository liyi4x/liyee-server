#include "log/log.h"

namespace liyee
{

const std::string LogLevel::toString(const LogLevel::Level& level)
{
    switch(level)
    {
    #define CASE(e) case e: return #e
        CASE(DEBUG);
        CASE(INFO);
        CASE(WARN);
        CASE(ERROR);
        CASE(FATAL);
    #undef CASE
    default:
        return "UNKONWN";
        break;
    }
}
const LogLevel::Level fromString(const std::string& s)
{
    LogLevel::Level res;
    if(s == "DEBUG" || s == "debug")
        res = LogLevel::Level::DEBUG;
    else if(s == "INFO" || s == "info")
        res = LogLevel::Level::INFO;
    else if(s == "WARN" || s == "warn")
        res = LogLevel::Level::WARN;
    else if(s == "ERROR" || s == "error")
        res = LogLevel::Level::ERROR;
    else if(s == "FATAL" || s == "fatal")
        res = LogLevel::Level::FATAL;

    return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


LogEvent::LogEvent(const std::string& loggerName, const std::string& fileName, uint32_t lineNumber,
                   LogLevel::Level level, pid_t threadID, pid_t fiberID, const std::string& threadName)
                  :m_loggerName(loggerName), m_fileName(fileName), m_lineNumber(lineNumber),
                   m_level(level), m_threadID(threadID), m_fiberID(fiberID), m_threadName(threadName)
{
    m_timeStamp = time(NULL);
    m_elapse = 0;
}

LogEvent::LogEvent(const std::string& loggerName, time_t timeStamp, time_t elapse, const std::string& fileName, uint32_t lineNumber,
        LogLevel::Level level, pid_t threadID, pid_t fiberID, const std::string& threadName)
        :m_loggerName(loggerName), m_timeStamp(timeStamp), m_elapse(elapse), m_fileName(fileName), m_lineNumber(lineNumber),
        m_level(level), m_threadID(threadID), m_fiberID(fiberID), m_threadName(threadName)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


// time_t m_timeStamp;         // %T 时间戳
// time_t m_elapse;            // %e 程序启动耗时
// const std::string& m_fileName;     // %F 文件名
// uint32_t m_lineNumber;      // %L 行号
// LogLevel::Level m_level;    // %p 日志等级
// pid_t m_threadID;           // %t 线程ID
// pid_t m_fiberID;            // %f 协程ID
// std::string m_threadName;   // %n 线程名
// std::string m_loggerName;   // %N 日志器名

LogFormatter::LogFormatter(std::ostream& outStream, const std::string& pattern): m_outStream(outStream), m_pattern(pattern)
{
    std::string str;

    for(int i = 0; i < m_pattern.size(); ++i)
    {
        if(m_pattern[i] != '%')
        {
            str.append(1, m_pattern[i]);
            continue;
        }
        else if(m_pattern[i] == '%' && i + 1 < m_pattern.size())
        {
            if(m_pattern[i+1] == '%')
            {
                str.append(1, m_pattern[i]);
                ++i;
                continue;
            }
        }

        m_fmt_items.push_back(FormatterItem::ptr(new StringItem(str)));
        str.clear();

        ++i;
        switch(m_pattern[i])
        {
            case 'T': m_fmt_items.push_back(FormatterItem::ptr(new TimeStampItem("%Y-%M-%D %h:%m:%s"))); break;
            case 'e': m_fmt_items.push_back(FormatterItem::ptr(new ElapseItem())); break;
            case 'F': m_fmt_items.push_back(FormatterItem::ptr(new FileNameItem())); break;
            case 'L': m_fmt_items.push_back(FormatterItem::ptr(new LineNumberItem())); break;
            case 'p': m_fmt_items.push_back(FormatterItem::ptr(new LevelItem())); break;
            case 't': m_fmt_items.push_back(FormatterItem::ptr(new ThreadIDItem())); break;
            case 'f': m_fmt_items.push_back(FormatterItem::ptr(new FiberIDItem())); break;
            case 'n': m_fmt_items.push_back(FormatterItem::ptr(new ThreadNameItem())); break;
            case 'N': m_fmt_items.push_back(FormatterItem::ptr(new LoggerNameItem())); break;
            default : m_fmt_items.push_back(FormatterItem::ptr(new StringItem("<<<error format>>>")));
        }
    }
    m_fmt_items.push_back(FormatterItem::ptr(new StringItem(str)));   //非%字符会continue跳过，处理最后一个字符串
}


// //这个版本不能实现 “%%”的解析，不能输出%
// LogFormatter::LogFormatter(std::ostream& outStream, const std::string& m_pattern): m_outStream(outStream)
// {
//     for(int i = 0; i < m_pattern.size(); ++i)
//     {
//         int j = i;
//         while(j < m_pattern.size() && m_pattern[j] != '%') //j指向%
//             ++j;
//         if(j != i)
//             m_fmt_items.push_back(FormatterItem::ptr>(new StringItem(m_pattern.substr(i, j-i))));
//         if(j >= m_pattern.size()) //如果是最后一个字符串的话，会出现 j=m_pattern.size()的情况，避免后边i访问越界
//             break;
//         i = j + 1;    //i指向%后边的字母

//         switch(m_pattern[i])
//         {
//             case 'T': m_fmt_items.push_back(FormatterItem::ptr>(new TimeStampItem("%Y-%M-%D %h:%m:%s"))); break;
//             case 'e': m_fmt_items.push_back(FormatterItem::ptr>(new ElapseItem())); break;
//             case 'F': m_fmt_items.push_back(FormatterItem::ptr>(new FileNameItem())); break;
//             case 'L': m_fmt_items.push_back(FormatterItem::ptr>(new LineNumberItem())); break;
//             case 'p': m_fmt_items.push_back(FormatterItem::ptr>(new LevelItem())); break;
//             case 't': m_fmt_items.push_back(FormatterItem::ptr>(new ThreadIDItem())); break;
//             case 'f': m_fmt_items.push_back(FormatterItem::ptr>(new FiberIDItem())); break;
//             case 'n': m_fmt_items.push_back(FormatterItem::ptr>(new ThreadNameItem())); break;
//             case 'N': m_fmt_items.push_back(FormatterItem::ptr>(new LoggerNameItem())); break;
//             default : m_fmt_items.push_back(FormatterItem::ptr>(new StringItem("<<<error format>>>")));
//         }
//     }
// }


void LogFormatter::formate(LogEvent& event)
{
    for(auto i = m_fmt_items.begin(); i != m_fmt_items.end(); ++i)
    {
        (*i)->format(m_outStream, event);
    }
    m_outStream << event.getStringStream().str() << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


LogAppender::LogAppender(const LogLevel::Level& level): m_level(level)
{
}

void LogAppender::SetLevel(const LogLevel::Level& level)
{
    m_level = level;
}



StdOutAppender::StdOutAppender(const std::string& fmt, const LogLevel::Level& level): LogAppender(level)
{
    m_formatter.reset(new LogFormatter(std::cout, fmt));
}


void StdOutAppender::log(LogEvent& event)
{
    if(event.getLevel() >= m_level)
        m_formatter->formate(event);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


Logger::Logger(const std::string& name): m_loggerName(name)
{
}

void Logger::AddAppender(const std::string& name, LogAppender::ptr appender)
{
    assert(m_logappenders.find(name) == m_logappenders.end());
    m_logappenders.insert(std::pair<std::string, LogAppender::ptr>(name, appender));
}

void Logger::DelAppender(const std::string& name)   //todo: 处理name字段重复的情况
{
    auto i = m_logappenders.find(name);
    assert(i != m_logappenders.end());
    m_logappenders.erase(name);     //erase返回值为成功删除的元素的个数，如果name不存在返回0
}

void Logger::ClearAppenders()
{
    m_logappenders.clear();
}

void Logger::SetLevel(const std::string& name, const LogLevel::Level& level)
{
    auto i = m_logappenders.find(name);
    assert(i != m_logappenders.end());
    i->second->SetLevel(level);
}

void Logger::SetLevel(const LogLevel::Level& level)
{
    for(auto& i: m_logappenders)
        i.second->SetLevel(level);
}

void Logger::log(LogEvent& event)
{
    for(auto& i : m_logappenders)
    {
        i.second->log(event);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


LoggerManager::LoggerManager()
{
    m_loggers.insert(std::pair<std::string, Logger::ptr>("root", new Logger("root")));
    m_loggers["root"]->AddAppender("stdout", std::make_shared<StdOutAppender>("%T\t%e\t%F:%L\t%p\t%t\t%f\t%n\t%N\t", LogLevel::Level::DEBUG));
}

void LoggerManager::AddLogger(const std::string& name)
{
    assert(m_loggers.find(name) == m_loggers.end());
    m_loggers.insert(std::pair<std::string, Logger::ptr>(name, new Logger(name)));
}

void LoggerManager::DelLogger(const std::string& name)
{
    auto i = m_loggers.find(name);
    assert(i != m_loggers.end());
    m_loggers.erase(i);
}

Logger::ptr LoggerManager::GetLogger(const std::string& name)
{
    auto i = m_loggers.find(name);
    assert(i != m_loggers.end());
    return i->second;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


LogEventSender::LogEventSender(Logger::ptr logger, std::shared_ptr<LogEvent> event): m_logger(logger), m_event(event)
{
}

LogEventSender::~LogEventSender()
{
    m_logger->log(*m_event);
}

std::stringstream& LogEventSender::GetSS()
{
    return m_event->getStringStream();
}




}// !namespace
