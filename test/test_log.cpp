
#include "log/log.h"


int main(int argc, char const *argv[])
{
    // liyee::start___ =  std::chrono::steady_clock::now();


    auto logger = liyee::LogMng::get()->GetLogger();

    // logger->AddAppender("tr", std::make_shared<liyee::StdOutAppender>("%T{%Y-%m-%d %H:%M:%S}\t%e\t%F:%L\t%p\t%t\t%f\t%n\t%N\t", liyee::LogLevel::Level::WARN));

    LIYEE_LOG_DEBUG(logger) << "hello world!!!";
    LIYEE_LOG_INFO(logger) <<  "hello world!!!";
    LIYEE_LOG_WARN(logger) <<  "hello world!!!";
    while(1)
    {

    LIYEE_LOG_ERROR(logger) << "hello world!!!";
    sleep(1);
    }

    // logger->DelAppender("tr");
    // LIYEE_LOG_FATAL(logger) << "hello world!!!";

    return 0;
}
