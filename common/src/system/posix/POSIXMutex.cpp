////////////////////////////////////////////////////////////////////////////////
/// @file POSIXMutex.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Implementation of POSIXMutex
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include <errno.h>
#include <pthread.h>
#include <string.h>

#include <cassert>

#include "errors/SystemException.hpp"
#include "fatal.hpp"
#include "system/os/OSMutex.hpp"

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
void init(mutex_t &mutex)
{
    pthread_mutexattr_t attr;
    int32_t ret = pthread_mutexattr_init(&attr);
    if (0 != ret)
    {
        std::string errorCode = "Failed to create mutex: " + std::string(strerror(ret)) + "!";
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }

    ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    if (0 != ret)
    {
        std::string errorCode = "Failed to create mutex: " + std::string(strerror(ret)) + "!";
        pthread_mutexattr_destroy(&attr);
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }

    ret = pthread_mutex_init(&mutex, &attr);
    if (0 != ret)
    {
        std::string errorCode = "Failed to create mutex: " + std::string(strerror(ret)) + "!";
        pthread_mutexattr_destroy(&attr);
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }

    ret = pthread_mutexattr_destroy(&attr);
    if (0 != ret)
    {
        std::string errorCode = "Failed to create mutex: " + std::string(strerror(ret)) + "!";
        pthread_mutex_destroy(&mutex);
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }
}

void destroy(mutex_t &mutex)
{
    int32_t ret = pthread_mutex_destroy(&mutex);
    if (ret != 0)
    {
        std::string errorCode = "Failed to destroy mutex: " + std::string(strerror(ret)) + "!";
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }
}

void lock(mutex_t &mutex)
{
    int32_t ret = pthread_mutex_lock(&mutex);
    if (ret != 0)
    {
        std::string errorCode = "Failed to aquire mutex: " + std::string(strerror(ret)) + "!";
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }
}

bool trylock(mutex_t &mutex)
{
    bool result = false;
    int32_t ret = pthread_mutex_trylock(&mutex);
    if (ret == 0)
    {
        result = true;
    }
    else if (ret == EBUSY)
    {
        result = false;
    }
    else
    {
        std::string errorCode = "Failed to aquire mutex: " + std::string(strerror(ret)) + "!";
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }
    return result;
}

void unlock(mutex_t &mutex)
{
    int32_t ret = pthread_mutex_unlock(&mutex);
    if (ret != 0)
    {
        std::string errorCode = "Failed to release mutex: " + std::string(strerror(ret)) + "!";
        FATAL_PRINT("%s", errorCode.c_str());
        throw happybus::common::errors::SystemException(errorCode);
    }
}

}  // namespace mutex
}  // namespace os
}  // namespace system
}  // namespace common
}  // namespace happybus
