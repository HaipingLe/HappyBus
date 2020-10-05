////////////////////////////////////////////////////////////////////////////////
/// @file types.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Header file for types
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////

#ifndef HAPPYBUS_COMMON_SYSTEM_TYPES_HPP
#define HAPPYBUS_COMMON_SYSTEM_TYPES_HPP

#include <stdint.h>

//Platform Definition
#if defined(unix) || defined(__unix__) || defined(__unix)
#define TARGET_OS_UNIX
#endif

namespace happybus
{
namespace common
{
namespace system
{
enum SchedulingPolicy
{
    SCHED_POLICY_NORMAL = 0,
    SCHED_POLICY_FIFO = 1,
    SCHED_POLICY_RR = 2,
    SCHED_POLICY_INVALID,
    SCHED_POLICY_LAST
};
}
} // namespace common
} // namespace happybus

/*
 *  UNIX-like OS
 */
#if defined(TARGET_OS_UNIX) || defined(__APPLE__)
#include <pthread.h>
#include <semaphore.h>
typedef pthread_t thread_id_t;
typedef int32_t os_priority_t;
typedef pthread_mutex_t mutex_t;
typedef pthread_mutex_t smallmutex_t;

#if defined(TARGET_OS_POSIX_LINUX) 
struct semaphore_t;
#else
typedef sem_t semaphore_t;
#endif

typedef pthread_key_t tls_key_t;
struct os_onceinit_t
{
    bool m_Flag;
    pthread_mutex_t m_Mutex;
};
typedef pthread_cond_t condvar_t;
#define OS_ONCEINIT                      \
    {                                    \
        false, PTHREAD_MUTEX_INITIALIZER \
    }

typedef int filehandle_t;
static const filehandle_t null_filehandle = -1;
typedef int errornumber_t;

typedef int scheduling_policy_t;
typedef uint32_t pretty_thread_id_t;

/*
 *  WIN32
 */
#elif defined(TARGET_OS_WIN32)

/*
 *  SYSBIOS
 */
#elif defined(TARGET_OS_SYSBIOS)

/*
 *  FreeRTOS
 */
#elif defined(TARGET_OS_FREERTOS)

#endif /* POSIX, CYGWIN, WIN32, SYSBIOS, FREERTOS */

typedef uint32_t cpu_affinity_t;

#endif
