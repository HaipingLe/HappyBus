////////////////////////////////////////////////////////////////////////////////
/// @file Mutex.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Mutex abstraction
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_SYSTEM_MUTEX_HPP
#define HAPPYBUS_COMMON_SYSTEM_MUTEX_HPP

/*-----------------------------------------------------------------------------
 * INCLUDES
 *---------------------------------------------------------------------------*/
#include "props/Uncopyable.hpp"
#include "os/OSMutex.hpp"

namespace happybus
{
namespace common
{
namespace system
{

class Mutex;

namespace os
{
namespace condvar
{

extern void wait(cond_var_t &, Mutex &);
extern bool wait(cond_var_t &, Mutex &, uint32_t);

} // namespace condvar
} // namespace os

/*-----------------------------------------------------------------------------
 * CLASS DECLARATIONS
 *---------------------------------------------------------------------------*/

/*
 * Mutex abstraction built on OS calls.
 * The purpose of this class is to provide OS independent access to a recursive mutex.
 *
 * It means that the same thread can lock the same mutex twice and won't lead to deadlock. Of course the mutex also
 * needs to be unlocked twice, otherwise it can't be obtained by any other thread.
 */
class Mutex : public happybus::common::props::Uncopyable
{
public:
    /*
        * Used as parameters to a wait call to determine the behavior whether the
        * mutex is locked when a lock request is made.
        */
    enum class Mode
    {
        NON_BLOCKING,
        BLOCKING
    };

    /*
        * Constructor, creates a new instance of a Mutex.
        */
    Mutex();

    /*
        * Destructor, destroys this mutex.
        */
    ~Mutex();

    /*
        * Lock this mutex. If the mode is blocking then wait forever for the
        * mutex to become available.
        * If the mode is nonBlocking then return immediately regardless
        * of mutex state. Return true if the mutex was free or
        * false if it was not free.
        *
        * \param mode lock blocking or nonblocking
        * \return true if the mutex was free, false if it was not free
        */
    bool lock(const Mode mutexMode = Mode::BLOCKING);

    /*
        * Attempts to lock the mutex. If the lock was obtained, this function returns true.
        * If another thread has locked the mutex, this function returns false immediately.
        *
        * \return true if the lock was free, false otherwise
        */
    bool trylock();

    /*
        * Unlocks this mutex object.  The mutex must be unlocked from the
        * same thread context that obtained the mutex or an error is returned.
        */
    void unlock();

private:
    // forbidden copy constructor
    Mutex(const Mutex &) = delete;
    // forbidden assignment operator
    Mutex &operator=(const Mutex &) = delete;

    mutex_t mMutex;

    // needed by SWCondVar.cpp to emulate CondVars
    friend void os::condvar::wait(cond_var_t &, Mutex &);
    friend bool os::condvar::wait(cond_var_t &, Mutex &, uint32_t);
};

} // namespace system
} // namespace common
} // namespace happybus

#endif