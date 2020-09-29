////////////////////////////////////////////////////////////////////////////////
/// @file BaseException.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Definition of the BaseException.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_ERRORS_BASEEXCEPTION_HPP
#define HAPPYBUS_COMMON_ERRORS_BASEEXCEPTION_HPP

#include <exception>
#include <list>
#include <sstream>
#include <string>

#include "types/Boolean.hpp"
#include "types/SmartPtr.hpp"
#include "Compiler.hpp"
#include "props/Cloneable.hpp"

namespace happybus
{
namespace common
{
namespace errors
{

/**
* Root of the exception tree.
* BaseExceptions may be chained. Meaning that one exception is the reason of
* another and so forth.
* However, chaining should not be used extensively as the objects grow larger
* and propagation takes more time.
*
* std::exception  https://en.cppreference.com/w/cpp/error/exception

* void fun() throw();               //It means that the function fun() is not allowed to throw any exception.
* void fun() throw(...);            //It means that the function fun() is allowed to throw any exception.
* void fun() throw(exceptionType);  //It means that the function fun() is only allowed to throw an exception, which type is exceptionType.
*/
class BaseException
    : public std::exception, public ::happybus::common::props::Cloneable<BaseException>
{
    friend class BaseExceptionTest;

public:
    /**
    * Construct an exception.
    *
    * Constructing a performance critical exception:
    *    BaseException("cause",0,true)
    *
    * Constructing an exception which is not performance critical:
    *    BaseException("cause")
    *
    *
    * @param[in] cause Optional textual message
    * @param[in] reason Pointer to the original exception that is the reason for
    * this one. The caller is responsible for destruction of the passed instance.
    * @param[in] perfCritical Is this a performance critical exception?
    */
    explicit BaseException( std::string const &cause = "", BaseException const *baseException = NULL,
                            happybus::common::types::Boolean perfCritical = false) throw();

    /*
    * Destructor.
    */
    virtual ~BaseException() throw() {}

    /**
    * Pointer to an exception.
    */
    typedef happybus::common::types::SmartPtr<BaseException> ExceptionPtr;

    /**
    * Ordered list of multiple exceptions.
    */
    typedef std::list<ExceptionPtr> ExceptionChain;

    /**
    * This iterator points to ExceptionPtr.
    */
    typedef ExceptionChain::const_iterator ExceptionChainIterator;

    /**
    * @return Iterator to the first element in the exception chain.
    * @note The final reason of an exception is the last element in this chain.
    */
    inline ExceptionChainIterator chainBegin() const
    {
        return mReasons.begin();
    }

    /**
    * @return Iterator to element after the last valid entry in the exception
    * chain.
    */
    inline ExceptionChainIterator chainEnd() const
    {
        return mReasons.end();
    }

    /*
    * @return Returns a null-terminated character sequence containing a generic
    * description of the error.
    */
    virtual const char *what() const throw();

    /*
    * \return Returns a null-terminated character sequence containing a stacktrace.
    */
    const char *getStacktrace() const throw()
    {
        return mStacktrace.c_str();
    }

    /*
    * Sometimes it is useful to modify the generic description of a exception
    * after construction.
    *
    * @param[in] cause generic description
    */
    void setCause(const std::string &cause)
    {
        mCause = cause;
    }

    /*
    * @return a generic description of want went wrong.
    */
    const std::string &getCause() const
    {
        return mCause;
    }

    /**
    * To be implemented by all derived classes, needs to throw an exception
    * of the derived class' type.
    */
    virtual void raise() = 0;

private:
    /*
    * Collects a stack trace.
    */
    void collectStacktrace( ::happybus::common::types::Boolean enableStacktrace = ::happybus::common::types::Boolean(true) );

    /*!
    * Description of this exception.
    */
    std::string mCause;

    /*!
    * A stacktrace.
    */
    std::string mStacktrace;

    /*!
    * Temporary string, used to provide a save return value for the function
    * what().
    */
    mutable std::string mWhat;

    /**
    * Chaining, with the original exception being the last in the chain.
    * The current exception is not stored in the chain.
    */
    ExceptionChain mReasons;
};

}  // namespace errors
}  // namespace common
}  // namespace happybus

#endif