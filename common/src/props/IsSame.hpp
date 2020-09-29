////////////////////////////////////////////////////////////////////////////////
//! @file IsSame.hpp
//!
//! @author Hubert lehaiping@126.com
///
/// @brief Test if given types are the same.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
////////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_PROPS_IS_SAME_HPP
#define HAPPYBUS_COMMON_PROPS_IS_SAME_HPP

namespace happybus
{
namespace common
{
namespace props
{

//explicit (full) template specialization
template <class T, class U>
struct is_same
{
    enum same
    {
        value = 0
    };
};

template <class T>
struct is_same<T, T>
{
    enum same
    {
        value = 1
    };
};
} // namespace props
} // namespace common
} // namespace happybus

#endif