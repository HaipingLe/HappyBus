////////////////////////////////////////////////////////////////////////////////
/// @file OSMutex.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Header file for OSMutex
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_SYSTEM_OSMUTEX_HPP
#define HAPPYBUS_COMMON_SYSTEM_OSMUTEX_HPP

/*-----------------------------------------------------------------------------
 * INCLUDES
 *---------------------------------------------------------------------------*/
#include "system/os/Types.hpp"

namespace happybus
{
namespace common
{
namespace system
{
namespace os
{
namespace mutex
{
/*-----------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 *---------------------------------------------------------------------------*/

/*
  The Linux OS provides the following 5 programming interfaces:
  1 int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
  2 int pthread_mutex_lock(pthread_mutex_t *mutex);
  3 int pthread_mutex_trylock(pthread_mutex_t *mutex);
  4 int pthread_mutex_unlock(pthread_mutex_t *mutex);
  5 int pthread_mutex_destroy(pthread_mutex_t *mutex);

  Therefore, I think the OS independent mutex abstraction should also contain the similar functions listed above.
*/
extern void init(mutex_t &mutex);

extern void destroy(mutex_t &mutex);

extern void lock(mutex_t &mutex);

extern bool trylock(mutex_t &mutex);

extern void unlock(mutex_t &mutex);

} // namespace mutex
} // namespace os
} // namespace system
} // namespace common
} // namespace happybus

#endif
