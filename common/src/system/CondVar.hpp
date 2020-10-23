////////////////////////////////////////////////////////////////////////////////
/// @file CondVar.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief OS Independent Condition variable abstraction
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_SYSTEM_CONDVAR_HPP
#define HAPPYBUS_COMMON_SYSTEM_CONDVAR_HPP

#include "system/os/OSCondVar.hpp"

namespace happybus 
{ 
namespace common 
{ 
namespace system
{
class CondVar : public happybus::common::props::Uncopyable
{
public:
   CondVar();
   ~CondVar();

   /**
    * Wait for condition variable to get signaled.
    *
    * The method must be called with @parameter mutex locked.
    * It means that the mutex object should be locked before using wait()
    * 
    * The method atomically releases mutex and cause the calling thread to be blocked one the condition variable.
    * The calling thread can be waked when the condition variable is signaled.
    *
    * @param mutex associated with the condition variable
    */
   void wait(happybus::common::system::Mutex& mutex);

   /**
    * Time limited wait for condition variable to be signaled.
    *
    * The method must be called with @paramter mutex locked.
    * It means that the mutex object should be locked before using wait()
    *
    * @param m Mutex associated with the condition variable
    * @param timeout Maximum time (in ms) to wait for signal
    * @return True if condition variable got signaled, false in case of timeout.
    */
   bool wait(happybus::common::system::Mutex& mutex, const uint32_t timeout);

   /**
    * Unblock at least one of the threads that are blocked on the condition
    * variable (if any threads are blocked).
    */
   void signal();

   /**
    * Unblock all threads currently blocked on the condition variable.
    */
   void broadcast();

private:
   cond_var_t mCondVar;
};

}
}
}
#endif