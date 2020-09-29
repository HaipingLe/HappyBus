////////////////////////////////////////////////////////////////////////////////
/// @file BaseException.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Implementation of the BaseException.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "errors/BaseException.hpp"
#include "Compiler.hpp"
/*************************************************
 * Default config for Stacktracing in exceptions *
 *************************************************/

/**
 * Controls if exceptions carry a corresponding stacktrace.
 */
#ifndef HAPPYBUS_COMMON_ENABLE_STACKTRACE_COLLECT_IN_EXCEPTIONS
#define HAPPYBUS_COMMON_ENABLE_STACKTRACE_COLLECT_IN_EXCEPTIONS 0
#endif

/**
 * When throwing exceptions it may be desirable to not
 * generate any stacktrace. For example if an exception is quite regular.
 *
 * In these critical paths the following variable should be used
 * to determine if a stacktrace is desired.
 *
 * Default: Stacktrace is disabled for performance critical paths.
 */
#ifndef HAPPYBUS_COMMON_STACKTRACE_PERF_CRITICAL_EXCEPTIONS
#define HAPPYBUS_COMMON_STACKTRACE_PERF_CRITICAL_EXCEPTIONS false
#endif


namespace happybus
{
namespace common
{
namespace errors
{

BaseException::BaseException(std::string const &cause, BaseException const *baseException,
                             happybus::common::types::Boolean perfCritical) throw():
    std::exception(),
    ::happybus::common::props::Cloneable<BaseException>(),
    mCause(cause),
    mStacktrace("no stacktrace"),
    mReasons()
{
    if (perfCritical)
    {
#if HAPPYBUS_COMMON_STACKTRACE_PERF_CRITICAL_EXCEPTIONS
        collectStacktrace();
#endif
    }
    else
    {
        collectStacktrace();
    }

    if (nullptr != baseException)
    {
        //copy the given exception instance.
        BaseException *e = baseException->clone();

        //save the current exception pointer firstly.
        mReasons.push_back(ExceptionPtr(e));

        if (!e->mReasons.empty())
        {
            //If exception chain is not empty
            //save each single exception pointer in the exception chain.
            mReasons.insert(mReasons.end(), e->mReasons.begin(), e->mReasons.end());

            // clean the chain of e because e-> mReasons has been saved in the new exception chain.
            e->mReasons.clear();
        }
    }
}

const char *BaseException::what() const throw()
{
    std::stringstream msg;
    msg << mCause << "\n" << mStacktrace << "\n";

    for (ExceptionChainIterator it = chainBegin(); it != chainEnd(); ++it)
    {
        msg << "Caused by: \n" << (**it).mCause << "\n" << (**it).mStacktrace << "\n";
    }
    mWhat = msg.str();
    return mWhat.c_str();
}

void BaseException::collectStacktrace(::happybus::common::types::Boolean enableStacktrace)
{
#if HAPPYBUS_COMMON_ENABLE_STACKTRACE_COLLECT_IN_EXCEPTIONS
    if ( enableStacktrace == true )
    {
        happybus::common::system::StackTrace stack;
        stack.collect();
        std::stringstream trace;
        trace << &std::endl;
        stack.dump(trace);
        mStacktrace = trace.str();
    }
#else
    //Avoid unused parameter warning from the compiler
    UNUSED(enableStacktrace);
#endif
}

}
}
}