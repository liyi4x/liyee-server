#include "thread.h"

namespace liyee
{

static thread_local Thread* t_thread = nullptr;
static thread_local std::string t_thread_name = "UNKONW";

Thread* Thread::GetThis()
{
  return t_thread;
}

std::string& Thread::GetName()
{
  return t_thread_name;
}
void Thread::SetName(std::string& name)
{
  if(t_thread)
    t_thread->m_name = name;
  t_thread_name = name;
}



Thread::Thread(std::function<void ()> cb, const std::string& name): m_cb(cb), m_name(name)
{
  if(name.empty())
    m_name = "UNKONW";
  int rt = pthread_create(&m_thread, nullptr, &Thread::run, this);
  if(rt)
  {
    //err
  }
}

Thread::~Thread()
{
  if(m_thread) {
    pthread_detach(m_thread);
  }
}

void Thread::join()
{
  if(m_thread)
  {
    int rt = pthread_join(m_thread, nullptr);
    if(rt)
    {
      //err
    }
    m_thread = 0;
  }
}

void* Thread::run(void* arg)
{
  Thread *thread = (Thread *)arg;
  t_thread = thread;
  t_thread_name = thread->m_name;
  thread->m_id = 1;//
}

} //!namespace
