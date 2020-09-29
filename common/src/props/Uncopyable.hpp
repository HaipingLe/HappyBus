////////////////////////////////////////////////////////////////////////////////
/// @file Uncopyable.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Header file for Uncopyable
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_PROPS_UNCOPYABLE_HPP
#define HAPPYBUS_COMMON_PROPS_UNCOPYABLE_HPP

namespace happybus
{
namespace common
{
namespace props
{

class Uncopyable
{
protected:
    Uncopyable() {}
    //The destructor is declared as veitrual so that the base class can be free via the pointer of the derived class.
    virtual ~Uncopyable() {}

    /*Note:
    To avoid copying operation, we can daclare the copy constructer and the assignment function as delete in C++ 11.
    We also have another solution, we can declare the copy constructer and the assignment function as pravite member and we don not implement it.
    */
    Uncopyable(const Uncopyable &) = delete;
    Uncopyable &operator=(const Uncopyable &) = delete;

#if 0
private:

    UnCopyable(const UnCopyable &);
    UnCopyable &operator=(const UnCopyable &);
#endif
};
} // namespace props
} // namespace common
} // namespace happybus
#endif