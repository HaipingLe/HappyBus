//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file ctassert.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief Compile-Time Assert Macro
///  The compile_time_assert works by generating an array-size-negative error if the predicate is violated.
///  We need a construct that can be used multiple times in the same scope.
///  In C++, we use typedef; C++ allows redundant typedefs in any scope.
///  However, if used inside of template functions and classes the redundant
///  typedefs will conflict, because the typedef is evaluated when the template
///  is actually instantiated.  Thus the compiler will initially assume that
///  the typedefs are not the same and complain.  As a work around we append the
///  current line number to the typedef name.  This way it's at least possible
///  to have multiple compile time assert statements on different lines.
///  In C, we use an 'extern' declaration; C does not allow redundant typedefs. However, 'extern' doesn't work at class scope in C++.
///  We use "void*" as the array base type, because that doesn't evoke a "direct use of fundamental type" warning.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_CTASSERT_HPP
#define HAPPYBUS_COMMON_CTASSERT_HPP

/* newer GCC versions will complain about unused local typedefs.  */
#if defined(__GNUC__)
#define compile_time_assert_unused_attribute __attribute__((unused))
#else
#define compile_time_assert_unused_attribute
#endif

#ifdef __cplusplus
/** Compile-Time Assert, C++ version.
    This macro can be used in
    - namespace scope
    - class scope
    - function scope
    \param x predicate */

/* helper macros to append the __LINE__ value to the typedef name, which results
   in something like 'compile_time_assert<N>', where N is the line number as
   substituted by the preprocessor.   */
#define compile_time_assert_name2(x, y) x ## y
#define compile_time_assert_name1(x, y) compile_time_assert_name2 (x, y)
#define compile_time_assert_name compile_time_assert_name1 (compile_time_assert_, __LINE__)

#define compile_time_assert(x) typedef void* compile_time_assert_name [(x) ? 1 : -1] compile_time_assert_unused_attribute

#else

/** Compile-Time Assert, C version.
    This macro can be used in
    - global scope
    - function scope
    \param x predicate */
#define compile_time_assert(x) extern void* compile_time_assert[(x) ? 1 : -1] compile_time_assert_unused_attribute
#endif

#endif
