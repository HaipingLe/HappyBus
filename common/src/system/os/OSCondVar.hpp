////////////////////////////////////////////////////////////////////////////////
/// @file OSCondVar.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief OS definitions for condition variables
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////

#ifndef HAPPYBUS_COMMON_SYSTEM_OSCONDVAR_HPP
#define HAPPYBUS_COMMON_SYSTEM_OSCONDVAR_HPP

#include "system/Mutex.hpp"
#include "system/os/Types.hpp"

namespace happybus
{ 
namespace common 
{ 
namespace system 
{
namespace os 
{ 
namespace condvar
{
/*-----------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 *---------------------------------------------------------------------------*/
/*
There are six related POSIX APIs for condition variable as follows:
    1>int pthread_cond_destroy(pthread_cond_t *cond);
    2>int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);

    3>int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);
    4>int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
    
    5>int pthread_cond_signal(pthread_cond_t *cond);
    6>int pthread_cond_broadcast(pthread_cond_t *cond);

    Therefore, I think the OS independent condition variable should also contain the similar functions listed above.

    Conditons variable should be combined with mutex and here is a simple example:
    https://zhuanlan.zhihu.com/p/98427480
    https://zhuanlan.zhihu.com/p/136431212
*/
extern void init(cond_var_t&);
extern void destroy(cond_var_t&);

extern void wait(cond_var_t&, happybus::common::system::Mutex&);
extern bool wait(cond_var_t&, happybus::common::system::Mutex&, uint32_t);
extern void signal(cond_var_t&);
extern void broadcast(cond_var_t&);

}
}
}
}
}

#endif