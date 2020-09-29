////////////////////////////////////////////////////////////////////////////////
/// @file Mutex.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Implementation of Mutex
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "Assert.hpp"
#include "Mutex.hpp"

namespace happybus
{
namespace common
{
namespace system
{

Mutex::Mutex() : happybus::common::props::Uncopyable(), mMutex()
{
    os::mutex::init(mMutex);
}

Mutex::~Mutex()
{
    try
    {
        os::mutex::destroy(mMutex);
    }
    catch (std::exception &e)
    {
        ASSERT_FATAL(false, "%s", e.what());
    }
    catch (...)
    {
        ASSERT_FATAL(false, "Unknown exception!");
    }
}

bool Mutex::lock(const Mode mutexMode)
{
    bool result = false;
    if (Mode::BLOCKING == mutexMode)
    {
        os::mutex::lock(mMutex);
        result = true;
    }
    else if (Mode::NON_BLOCKING == mutexMode)
    {
        result = os::mutex::trylock(mMutex);
    }
    else
    {
        ASSERT_FATAL(false, "Unknown lock mode!");
    }

    return result;
}

bool Mutex::trylock()
{
    bool result = false;
    result = os::mutex::trylock(mMutex);
    return result;
}

void Mutex::unlock()
{
    os::mutex::unlock(mMutex);
}

} // namespace system
} // namespace common
} // namespace tsd
