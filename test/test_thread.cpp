#include "thread.h"
#include "log/log.h"
#include <vector>

auto logger = liyee::LogMng::get()->GetLogger();

void thread_test()
{
    LIYEE_LOG_INFO(logger) << "name=" << liyee::Thread::GetName()
          << " id=" << liyee::Thread::GetThis()->getId();
    sleep(15);
}

int main(int argc, char const *argv[])
{
  std::vector<liyee::Thread::ptr> ths;

  for(int i = 0; i < 10; i++)
  {
    liyee::Thread::ptr th(new liyee::Thread(thread_test, "thread_" + std::to_string(i)));
    ths.push_back(th);
  }
  
  for(auto i : ths)
  {
    i->join();
  }

  for(int i = 0; i < 5; i++)
  {
    LIYEE_LOG_INFO(logger) << "main";
    sleep(1);
  }

  return 0;
}

