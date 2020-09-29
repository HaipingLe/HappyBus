////////////////////////////////////////////////////////////////////////////////
/// @file AtomicInteger.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Atomic Integer
/// This contains all implementations of AtomicInteger for all known platforms.
///
///  It is ordered from top to bottom:
///  - operating systems that have fast system calls
///  - assembler implementations
///  - slow replacement versions
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "system/AtomicInteger.hpp"
//#include "ctassert.hpp"

/*
 *  POSIX fallback solution (potentially slow)
 */
#include <pthread.h>
namespace
{
pthread_mutex_t atomicMutex = PTHREAD_MUTEX_INITIALIZER;
}

int32_t happybus::common::system::AtomicInteger::read(const int32_t &var)
{
    pthread_mutex_lock(&atomicMutex);
    int32_t ret = var;
    pthread_mutex_unlock(&atomicMutex);
    return ret;
}

void happybus::common::system::AtomicInteger::write(int32_t &var, int32_t value)
{
    pthread_mutex_lock(&atomicMutex);
    var = value;
    pthread_mutex_unlock(&atomicMutex);
}

int32_t happybus::common::system::AtomicInteger::exchangeAdd(int32_t &var, int32_t addend)
{
    pthread_mutex_lock(&atomicMutex);
    int32_t ret = var;
    var += addend;
    pthread_mutex_unlock(&atomicMutex);
    return ret;
}
