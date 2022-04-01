#include "utils/util.h"

namespace liyee
{

pid_t GetThreadId()
{
  return syscall(SYS_gettid);
}

pid_t GetFiberId()
{
  return 123;
}
const std::string& GetThreadName()
{
  return liyee::Thread::GetName();
}


}  // !namespace
