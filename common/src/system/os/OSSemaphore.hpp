////////////////////////////////////////////////////////////////////////////////
/// @file OSMutex.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief OS definitions for Semaphore
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_SYSTEM__OSSEMAPHORE_HPP
#define HAPPYBUS_COMMON_SYSTEM__OSSEMAPHORE_HPP

#include "system/os/Types.hpp"
#include "types/typedef.hpp"

namespace happybus
{ 
namespace common
{ 
namespace system
{ 
namespace semaphore 
{
/*-----------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 *---------------------------------------------------------------------------*/

/*
In the linux system, there are two kinds of semaphore: named semaphore 
and unamed semaphore(memory-based semaphore).

[named semaphore]        [unamed semaphore]             
sem_open()               sem_init()
          \             /
           \           /
             sem_wait()
             sem_trywait()
             sem_post()
             sem_getvalue()
           /               \
          /                 \
sem_close()                  sem_destroy()
sem_unlink()

In my project, i would like to use the unamed semaphore(memory-based), which only worksduring 
multiple threads within one process.
*/

extern void init( semaphore_t& semaphore, uint32_t value );

extern void destroy( semaphore_t& semaphore );

extern void down( semaphore_t& semaphore );

extern bool down( semaphore_t& semaphore, uint32_t millisecondsToSleep );

extern bool tryDown( semaphore_t& semaphore );

extern void up( semaphore_t& semaphore );

}
}
}
}
#endif