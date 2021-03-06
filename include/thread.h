#ifndef _THREAD_H_
#define _THREAD_H_

#include <thread>
#include <functional>
#include <memory>
#include <pthread.h>

namespace liyee
{

class Thread
{

public:
  typedef std::shared_ptr<Thread> ptr;

  Thread(std::function<void ()> cb, const std::string& name);
  ~Thread();

  pid_t getId() const {return m_id;}
  const std::string& getName() {return m_name;}

  void join();

  static Thread* GetThis();
  static std::string& GetName();
  static void SetName(std::string& name);

private:
  Thread(const Thread&) = delete;
  Thread(const Thread&&) = delete;  //右值引用
  Thread operator=(const Thread&) = delete;

  static void* run(void* arg);

private:
  pid_t m_id = -1;
  pthread_t m_thread = 0;
  std::function<void ()> m_cb;
  std::string m_name;

};

};  // !namespace

#endif // !_THREAD_H_
