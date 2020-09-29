/////////////////////////////////////////////////////////////////////////////////////////////////
/// @file AtomicInteger.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Header file for Atomic Integer
/// This is an integer, equivalent to a int32_t, which can be increased and
/// decreased atomically. Atomicality is defined within a "domain", which is
/// platform-dependant and at least consists of a process (address space,
/// C-program-with-main-function), not counting interrupts.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_SYSTEM_ATOMICINTEGER_HPP
#define HAPPYBUS_COMMON_SYSTEM_ATOMICINTEGER_HPP
#include <stdint.h>

namespace happybus
{
namespace common
{
namespace system
{

class AtomicInteger
{
public:
    AtomicInteger(int32_t n) : mValue(n) {}

    /** Get value. */
    operator int32_t() const
    {
        return read(mValue);
    }

    /** Set value. */
    void operator=(int32_t value)
    {
        write(mValue, value);
    }

    /** Add-and-Assign - increases the integer by value
        \return old value. It is guaranteed that if multiple threads within a
       domain call exchangeAdd-based operations simultaneously, each one sees a
       different return value. */
    int32_t operator+=(int32_t value)
    {
        return exchangeAdd(mValue, value);
    }

    /** Subtract-and-Assign - decreases the integer by value
        \return old value. It is guaranteed that if multiple threads within a
       domain call exchangeAdd-based operations simultaneously, each one sees a
       different return value. */
    int32_t operator-=(int32_t value)
    {
        return exchangeAdd(mValue, -value);
    }

    /** Increment by one.
        \return old value. It is guaranteed that if multiple threads within a
       domain call increment() simultaneously, each one sees a different return
       value. */
    int32_t increment()
    {
        return exchangeAdd(mValue, +1);
    }

    /** Decrement by one.
        \return old value. It is guaranteed that if multiple threads within a
       domain call decrement() simultaneously, each one sees a different return
       value. */
    int32_t decrement()
    {
        return exchangeAdd(mValue, -1);
    }

    /** Increment by one.
        Note that it is usually better to use increment which returns the old
       value. \returns *this */
    AtomicInteger &operator++()
    {
        increment();
        return *this;
    }

    /** Decrement by one.
        Note that it is usually better to use decrement which returns the old
       value. \returns *this */
    AtomicInteger &operator--()
    {
        decrement();
        return *this;
    }

private:
    /** The value. */
    int32_t mValue;

    // Platform-specific implementations
    static int32_t read(const int32_t &var);
    static void write(int32_t &var, const int32_t value);
    static int32_t exchangeAdd(int32_t &var, int32_t addend);
};

}  // namespace system
}  // namespace common
}  // namespace happybus

#endif
