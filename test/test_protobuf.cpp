#include "utils/io.h"
#include "log/log.h"
#include "proto/test.pb.h"


int main(int argc, char const *argv[])
{
    auto logger = liyee::LogMng::get()->GetLogger();
    LIYEE_LOG_DEBUG(logger) << "hello world!!!";

    liyee::proto::test_protobuf pp;

    liyee::ReadProtoFromTextFile("../conf/test/test.prototxt", &pp);
    std::cout << pp.goal_size() << std::endl;

    std::cout << pp.goal(1).y() << std::endl;
    std::cout << pp.goal(2).x() << std::endl;

    return 0;
}
