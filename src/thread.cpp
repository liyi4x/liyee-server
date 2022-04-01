#include "thread.h"
#include "utils/util.h"
#include "log/log.h"

namespace liyee
{

static thread_local Thread* t_thread = nullptr;
static thread_local std::string t_thread_name = "UNKONW";

static liyee::Logger::ptr logger_sys = liyee::LogMng::get()->GetLogger("system");

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
    LIYEE_LOG_ERROR(logger_sys) << "pthread_create fail, rt=" << rt
      << " name=" << m_name;
      throw std::logic_error("pthread_create error");
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
      LIYEE_LOG_ERROR(logger_sys) << "pthread_join fail, rt=" << rt
        << " name=" << m_name;
        throw std::logic_error("pthread_join error");
    }
    m_thread = 0;
  }
}

void* Thread::run(void* arg)
{
  Thread *thread = (Thread *)arg;
  t_thread = thread;
  t_thread_name = thread->m_name;
  thread->m_id = liyee::GetThreadId();  //获取线程ID 在top里面能看到的
  pthread_setname_np(pthread_self(), thread->m_name.substr(0, 15).c_str()); //设置线程名字，只能接收16个字符

  std::function<void()> cb;

  cb.swap(thread->m_cb);  //如果不swap的话，cb里面有智能指针的时候，不会释放
  
  cb();

  return nullptr;
}

} //!namespace
