
#include "log/log.h"


int main(int argc, char const *argv[])
{

    auto logger = liyee::LogMng::get()->GetLogger();

    logger->AddAppender("tr", std::make_shared<liyee::StdOutAppender>("%T\t%e\t%F:%L\t%p\t%t\t%f\t%n\t%N\t", liyee::LogLevel::Level::WARN));



    LIYEE_LOG_DEBUG(logger) << 123123;
    LIYEE_LOG_INFO(logger) << 123123;
    LIYEE_LOG_WARN(logger) << 123123;
    LIYEE_LOG_ERROR(logger) << 123123;

    logger->DelAppender("tr");
    LIYEE_LOG_FATAL(logger) << 123123;

    return 0;
}
