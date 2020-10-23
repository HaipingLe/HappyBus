////////////////////////////////////////////////////////////////////////////////
/// @file POSIXCondVar.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief POSIX condition variable implementation
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#include "errors/SystemException.hpp"
#include "fatal.hpp"
#include "system/CondVar.hpp"

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
void init(cond_var_t& cv)
{
}

void destroy(cond_var_t& cv)
{
}

void wait(cond_var_t& cv, happybus::common::system::Mutex& mutex)
{
}

bool wait(cond_var_t& cv, happybus::common::system::Mutex& mutex, uint32_t timeoutMS)
{
}

void signal(cond_var_t& cv)
{
}

void broadcast(cond_var_t& cv)
{
}

}
}
}
}
}