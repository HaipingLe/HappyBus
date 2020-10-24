////////////////////////////////////////////////////////////////////////////////
/// @file CondVar.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Implementation of OS Independent Condition Variable
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "system/CondVar.hpp"

namespace happybus
{ 
namespace common
{
namespace system
{

CondVar::CondVar(): mCondVar()
{
   os::condvar::init(mCondVar);
}

CondVar::~CondVar()
{
   os::condvar::destroy(mCondVar);
}

void CondVar::wait(happybus::common::system::Mutex& mutex)
{
   os::condvar::wait(mCondVar, mutex);
}

bool CondVar::wait(happybus::common::system::Mutex& mutex, const uint32_t timeoutMS)
{
   return os::condvar::wait(mCondVar, mutex, timeoutMS);
}

void CondVar::signal()
{
   os::condvar::signal(mCondVar);
}

void CondVar::broadcast()
{
   os::condvar::broadcast(mCondVar);
}

}
}
}