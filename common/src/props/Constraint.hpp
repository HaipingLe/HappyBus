////////////////////////////////////////////////////////////////////////////////
/// @file   Constraint.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Type definition depending on a condition.
///
////////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_PROPS_CONSTRAINT_HPP
#define HAPPYBUS_COMMON_PROPS_CONSTRAINT_HPP

namespace happybus
{
namespace common
{
namespace props
{

template <bool b, class T>
struct constraint;  // no type definition

template <class T>
struct constraint<true, T>
{
    typedef T type;  // define type to T
};
}  // namespace props
}  // namespace common
}  // namespace happybus

#endif  // #define CONSTRAINT_HPP
