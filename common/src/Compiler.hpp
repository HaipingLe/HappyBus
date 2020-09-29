////////////////////////////////////////////////////////////////////////////////
/// @file Compiler.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Contains some helpful macros and definitions for the compiler.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_COMPILER_HPP
#define HAPPYBUS_COMMON_COMPILER_HPP

/*! macro DEPRECATED
    @brief Declare a deprecated function

    Use as "DEPRECATED void foo()" in the head file.
    There will be a warning provided via the specific compiler when trying
    to use the function. */

#if !defined (DEPRECATED)
#if defined(__GNUC__)
#define GCC_VERSION_AT_LEAST(x,y) (__GNUC__ > (x) || __GNUC__ == (x) && __GNUC_MINOR__ >= (y))
#else
#define GCC_VERSION_AT_LEAST(x,y) 0
#endif

#if GCC_VERSION_AT_LEAST(3,1)
/* GCC 3.1 and higher */
#define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
/* MSVC 2003 (or something in that range) */
#define DEPRECATED __declspec(deprecated)
#else
#define DEPRECATED
#endif
#endif

/*! \macro UNUSED
    @brief Avoid unused parameter warnings.
    we can use "g++ -Wall main.cpp -o out" to verify if this marco works.
    It can be aslo written as
    #define UNUSED( x )  (void)(x)
 */
#define UNUSED( x ) static_cast< void >( x )


/*! \macro FUNCTION_PRINTF
    @brief __attribute__((format(printf,m,n)))
    This __attribute__ allows assigning printf-like or scanf-like characteristics to the declared function,
    and this enables the compiler to check the format string against the provided parameters.
    This is extraordinarily helpful in tracking down hard-to-find bugs.

    @param FormatIndex: the index of the format string in parameters list, counting start by one.
                        For memberfunction you need to start by two because of the hidden this pointer parameter.
    @param ParamIndex : the index of the first variable arguments in parameters list

    @Example:
    #include <iostream>

    #if defined(__GNUC__)
    #define FUNCTION_PRINTF(FormatIndex, ParamIndex) __attribute__ ((format (printf, FormatIndex, ParamIndex)))
    #else
    # define FUNCTION_PRINTF(FormatIndex, ParamIndex)
    #endif


    void FUNCTION_PRINTF(1,2) foo(const char *fmt, ...)
    {
        std::cout << "Hello, foo()!" << std::endl;
    }

    class Test
    {
    public:
        void FUNCTION_PRINTF(2,3) foo(const char *fmt, ...)
        {
            std::cout << "Hello, Test::foo()!" << std::endl;
        }
    };

    int main(void)
    {
        foo("Value = %d\n", 6); //right
        //foo("Value = %s%d\n", "6",6); //error
        foo("Value = %s%d\n", "6",6); //right

        Test t;
        t.foo("Value = %d\n", 6); //right
        t.foo("Value = %d%d\n", 6,6);//right
        t.foo("Value = %d%s\n", 6,"6");//error
        return 0;
    }
*/

#if defined(__GNUC__)
#define FUNCTION_PRINTF(FormatIndex, ParamIndex) __attribute__ ((format (printf, FormatIndex, ParamIndex)))
#else
# define FUNCTION_PRINTF(FormatIndex, ParamIndex)
#endif

/*! \macro LIKELY, UNLIKELY
    \brief Tell the compiler whether code paths are likely to be
    executed or not.  It allows the compiler to reorder basic blocks in the
    code so that paths that are likely will be reached with fewer branches.
    Example:

    if (LIKELY (objptr.get () != NULL))
    {
      code that is usually expected to be executed most of the time
    }
    else
    {
      code that is usually not expected to be executed most of the time
    }
*/
#if defined(__GNUC__) && !defined(__TI_COMPILER_VERSION__)
#define LIKELY(x)       __builtin_expect((x), 1)
#define UNLIKELY(x)     __builtin_expect((x), 0)
#else
#define LIKELY(x)       (x)
#define UNLIKELY(x)     (x)
#endif

/* 64 Bit handling */
// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define HAPPYBUS_COMPILER_64
#define HAPPYBUS_COMPILER_LLP64
#else
#define HAPPYBUS_COMPILER_32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__ || __LP64__ || __aarch64__
#define HAPPYBUS_COMPILER_64
#define HAPPYBUS_COMPILER_LP64
#else
#define HAPPYBUS_COMPILER_32
#endif
#endif

#endif /* HAPPYBUS_COMMON_COMPILER_HPP  */