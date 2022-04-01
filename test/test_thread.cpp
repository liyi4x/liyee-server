#include "thread.h"

void tttt()
{
  ;
}

int main(int argc, char const *argv[])
{
  std::function<void ()> ss = tttt;
  std::string name = "123";
  
  liyee::Thread th(ss, name);

  return 0;
}

