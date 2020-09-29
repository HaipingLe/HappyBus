////////////////////////////////////////////////////////////////////////////////
/// @file Cloneable.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief The Base Class of Cloneable opbjects
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_CLONEABLE_HPP
#define HAPPYBUS_COMMON_CLONEABLE_HPP

namespace happybus
{
namespace common
{
namespace props
{
template <class T>
class Cloneable
{
public:
    virtual ~Cloneable()
    {
    }

    /**
         * Create a copy of this.
         * \return Copy with newly allocated object.
         */
    virtual T *clone() const = 0;
};

} // namespace props
} // namespace common
} // namespace happybus

#endif // #define CLONEABLE_HPP
