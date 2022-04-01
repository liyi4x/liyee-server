#include "log/log.h"

int main(int argc, char const *argv[])
{
  auto logger = liyee::LogMng::get()->GetLogger();

  logger->AddAppender("file", std::make_shared<liyee::FileAppender>("%T{%Y-%m-%d %H:%M:%S}\t%e\t%F:%L\t%p\t%t\t%f\t%n\t%N\t"));

  auto log_sys = liyee::LogMng::get()->GetLogger("system");

  LIYEE_LOG_DEBUG(logger) << "hello world!!!";
  LIYEE_LOG_INFO(logger) <<  "hello world!!!";
  LIYEE_LOG_WARN(logger) <<  "hello world!!!";

  LIYEE_LOG_DEBUG(log_sys) << "hello world!!!";
  LIYEE_LOG_INFO(log_sys) <<  "hello world!!!";
  LIYEE_LOG_WARN(log_sys) <<  "hello world!!!";
  while(1)
  {
    LIYEE_LOG_ERROR(logger) << "hello world!!!";
    LIYEE_LOG_ERROR(log_sys) << "hello world!!!";
    sleep(1);
  }
  
  // LIYEE_LOG_FATAL(logger) << "hello world!!!";

  return 0;
}
