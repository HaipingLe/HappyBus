////////////////////////////////////////////////////////////////////////////////
/// @file SystemException.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Definition of the SystemException.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_ERRORS_SYSTEMEXCEPTION_HPP
#define HAPPYBUS_COMMON_ERRORS_SYSTEMEXCEPTION_HPP

#include "errors/BaseException.hpp"

namespace happybus
{
namespace common
{
namespace errors
{

class SystemException: public BaseException
{
public:
    explicit SystemException( std::string const &what) throw ()
        : BaseException(what)
    {
    }

    virtual void raise()
    {
        throw *this;
    }

    virtual BaseException *clone() const
    {
        return new SystemException(*this);
    }

};
}
}
}

#endif
