#ifndef _UTIL_H_
#define _UTIL_H_

#include <sys/syscall.h>
#include <unistd.h>
#include "thread.h"

namespace liyee
{

pid_t GetThreadId();
pid_t GetFiberId();
const std::string& GetThreadName();

}  // !namespace

#endif // _UTIL_H_
