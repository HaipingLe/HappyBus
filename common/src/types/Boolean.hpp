////////////////////////////////////////////////////////////////////////////////
/// @file Boolean.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief A wrapper of standrad bool type
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_TYPES_BOOLEAN
#define HAPPYBUS_COMMON_TYPES_BOOLEAN

#include "props/Constraint.hpp"
#include "props/IsSame.hpp"

namespace happybus
{
namespace common
{
namespace types
{

/**
 * To provide a bool type with stricter conversion rules.
 * It prohibits implicit standard type conversion:
 * Only the standard type bool can be converted to and from this.
 *
 * This is useful when you have function overloads with pointer-based
 * arguments and bool arguments. For Enample:
 *
 * void func(char *msg = 0)
 * void func(bool b = true)
 *
 * One may call func(false) and unexpectedly call the overload with char*.
 * Instead, simply use Boolean as parameter for the second overload:
 *
 * void func(Boolean b = true)
 *
 * Thus the compiler may not implicitely convert false to (char*) 0.
 *
 */
class Boolean
{
public:
    /**
     * Implicit conversion of bool to Boolean. The second parameter
     * disallows standard conversion of other types, such
     * as void* or int to Bool.
     * \param[in] b the boolean value
     * \param[in] type controls template instantiation: constructor can
     * only be instantiated for T = bool.
     */
    template <class T>
    // The motivation of using typename here is to tell the compiler that
    // props::constraint<props::is_same<bool, T>::value, bool>::type is a type that
    // defined via props::constraint
    inline Boolean(T b, typename props::constraint<props::is_same<bool, T>::value,
                   bool>::type = true)
        : mValue(b) {}

    /**
     * Convert this to bool standard type.
     */
    inline operator bool() const
    {
        return mValue;
    }

private:
    bool mValue;
};
}  // namespace types
}  // namespace common
}  // namespace happybus
#endif