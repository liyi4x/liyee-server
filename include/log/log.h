#ifndef _LIYEE_LOG_H_
#define _LIYEE_LOG_H_

#include <string>
#include <chrono>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <sys/syscall.h>  
#include <unistd.h>
#include <assert.h>

#define LIYEE_LOG__(logger, level)\
  liyee::LogEventSender(logger, std::make_shared<liyee::LogEvent>("logger", __FILE__, __LINE__, level, syscall(SYS_gettid), 0, "threadName")).GetSS()
#define LIYEE_LOG_DEBUG(logger)  LIYEE_LOG__(logger, liyee::LogLevel::DEBUG)
#define LIYEE_LOG_INFO(logger)   LIYEE_LOG__(logger, liyee::LogLevel::INFO)
#define LIYEE_LOG_WARN(logger)   LIYEE_LOG__(logger, liyee::LogLevel::WARN)
#define LIYEE_LOG_ERROR(logger)  LIYEE_LOG__(logger, liyee::LogLevel::ERROR)
#define LIYEE_LOG_FATAL(logger)  LIYEE_LOG__(logger, liyee::LogLevel::FATAL)

namespace liyee
{

std::chrono::time_point<std::chrono::steady_clock> start___ = std::chrono::steady_clock::now();

class LogLevel
{
public:
  enum Level
  {
    UNKONWN = 0,
    DEBUG   = 1,
    INFO    = 2,
    WARN    = 3,
    ERROR   = 4,
    FATAL   = 5
  };

  static const std::string toString(const LogLevel::Level& level);
  static const LogLevel::Level fromString(const std::string& s);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////


class LogEvent
{
public:
  LogEvent(const std::string& loggerName, const std::string& fileName, uint32_t lineNumber, LogLevel::Level level,
      pid_t threadID, pid_t fiberID, const std::string& threadName);
  LogEvent(const std::string& loggerName, time_t m_timeStamp, uint32_t m_elapse, const std::string& m_fileName, uint32_t m_lineNumber,
      LogLevel::Level level, pid_t m_threadID, pid_t m_fiberID, const std::string& m_threadName);
  const time_t            getTimeStamp()  const {return m_timeStamp;}
  const uint32_t          getElapse()     const {return m_elapse;}
  const std::string&      getFileName()   const {return m_fileName;}
  const uint32_t          getLineNumber() const {return m_lineNumber;}
  const LogLevel::Level&  getLevel()      const {return m_level;}
  const pid_t             getThreadID()   const {return m_threadID;}
  const pid_t             getFiberID()    const {return m_fiberID;}
  const std::string       getThreadName() const {return m_threadName;}
  const std::string       getLoggerName() const {return m_loggerName;}
  std::stringstream&      getStringStream(){return m_ss;}
private:
  time_t m_timeStamp;         // %t 时间戳
  uint32_t m_elapse;          // %e 程序启动耗时
  std::string m_fileName;     // %F 文件名
  uint32_t m_lineNumber;      // %L 行号
  LogLevel::Level m_level;    // %p 日志等级
  pid_t m_threadID;           // %p 线程ID
  pid_t m_fiberID;            // %f 协程ID
  std::string m_threadName;   // %n 线程名
  std::string m_loggerName;   // %N 日志器名
  std::stringstream m_ss;     //流的方式存储日志内容
};

///////////////////////////////////////////////////////////////////////////////////////////////////////


class LogFormatter
{
public:
  typedef std::shared_ptr<LogFormatter> ptr;
  LogFormatter(std::ostream& m_outStream, const std::string& pattern);   //构造格式器，即根据”%d %t...“填充 m_fmt_items
  void format(LogEvent& event); //遍历vector 组合日志的各个字段

public:
  class FormatterItem
  {
  public:
    typedef std::shared_ptr<FormatterItem> ptr;
    virtual ~FormatterItem(){};
    virtual void format(std::ostream& os, const LogEvent& event) = 0;
  };

private:
  std::ostream& m_outStream;  //组合后的输出流
  std::string m_pattern;
  std::vector<FormatterItem::ptr> m_fmt_items;
};

class StringItem : public LogFormatter::FormatterItem   //格式化序列中的原始字符串 “stringraw%p”中的 stringraw
{
public:
  StringItem(std::string s): m_str(s){}
  void format(std::ostream& os, const LogEvent& event) override {os << m_str;}
private:
  std::string m_str;
};

class TimeStampItem : public LogFormatter::FormatterItem
{
public:
  TimeStampItem(std::string fmt): m_fmt(fmt){}
  void format(std::ostream& os, const LogEvent& event) override
  {
    char buf[64];
    struct tm t;
    time_t time = event.getTimeStamp();
    localtime_r(&time, &t);
    strftime(buf, sizeof(buf), m_fmt.c_str(), &t);
    os << buf;
  }
private:
  std::string m_fmt;
};

class ElapseItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override
  {
    
    auto start___ = std::chrono::steady_clock::now();
    os << event.getElapse();
  }
};

class FileNameItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << event.getFileName();}
};

class LineNumberItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << event.getLineNumber();}
};

class LevelItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << '[' << LogLevel::toString(event.getLevel()) << ']';}
};

class ThreadIDItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << event.getThreadID();}
};

class FiberIDItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << event.getFiberID();}
};

class ThreadNameItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << event.getThreadName();}
};

class LoggerNameItem : public LogFormatter::FormatterItem
{
public:
  void format(std::ostream& os, const LogEvent& event) override {os << event.getLoggerName();}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////


class LogAppender
{
public:
  typedef std::shared_ptr<LogAppender> ptr;

  LogAppender(const LogLevel::Level& level = LogLevel::Level::DEBUG);
  virtual ~LogAppender(){}
  virtual void SetLevel(const LogLevel::Level& level);
  virtual void log(LogEvent& event) = 0;
protected:
  LogLevel::Level m_level;    //输出日志等级阈值
  LogFormatter::ptr m_formatter;
};

class StdOutAppender : public LogAppender
{
public:
  StdOutAppender(const std::string& fmt, const LogLevel::Level& level = LogLevel::Level::DEBUG);
  ~StdOutAppender(){}
  void log(LogEvent& event) override;
private:
};

class FileAppender : public LogAppender
{
public:
  FileAppender(const std::string& fmt, const std::string& fileName = "./log.txt", const LogLevel::Level& level = LogLevel::Level::DEBUG);
  ~FileAppender();
  void ReopenFile(const std::string& fileName);
  void log(LogEvent& event) override;
private:
  std::string m_fileName;
  std::fstream m_fileStream;
};


///////////////////////////////////////////////////////////////////////////////////////////////////////


class Logger
{
public:
  typedef std::shared_ptr<Logger> ptr;

  Logger(const std::string& name);
  void AddAppender(const std::string& name, LogAppender::ptr appender);
  void DelAppender(const std::string& name);
  void ClearAppenders();
  LogAppender::ptr GetAppender(const std::string& name);
  void SetLevel(const LogLevel::Level& level);
  void SetLevel(const std::string& name, const LogLevel::Level& level);
  void log(LogEvent& event);
private:
  std::string m_loggerName;
  std::map<std::string, LogAppender::ptr> m_logappenders;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////


class LoggerManager
{
public:
  LoggerManager();
  void AddLogger(const std::string& name);
  void DelLogger(const std::string& name);
  Logger::ptr GetLogger(const std::string& name = "root");
private:
  std::map<std::string, Logger::ptr> m_loggers;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////


class LogEventSender
{
public:
  LogEventSender(Logger::ptr logger, std::shared_ptr<LogEvent> event);
  ~LogEventSender();
  std::stringstream& GetSS();
private:
  Logger::ptr m_logger;
  std::shared_ptr<LogEvent>& m_event;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class SingleItem 
{
public:
  static T* get()
  {
    static T item;
    return &item;
  }
};

typedef SingleItem<LoggerManager> LogMng;
  
};  //!namespace

#endif // !_LIYEE_LOG_H_
