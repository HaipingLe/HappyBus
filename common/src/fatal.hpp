////////////////////////////////////////////////////////////////////////////////
/// @file fatal.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  error level tracing
///Usage:
///  - use FATAL_PRINT(format, args)
///  A wrapper for printf for printing out fatal error messages.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_FATAL_HPP
#define HAPPYBUS_COMMON_FATAL_HPP

#include <cstdio>

#define FATAL_PRINT (void)::std::printf

#endif
