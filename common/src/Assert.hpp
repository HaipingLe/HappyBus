////////////////////////////////////////////////////////////////////////////////
/// @file assert.hpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Provides some assert macros.
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_ASSERT_HPP
#define HAPPYBUS_COMMON_ASSERT_HPP

#include <stdlib.h>
#include <cstdio>
#include <exception>

void assertFatalExit();

#define ASSERT_FATAL(...)                              \
    {                                                  \
        std::printf("*** ASSERT_FATAL ***\n");         \
        std::printf("In %s:%d: ", __FILE__, __LINE__); \
        std::printf("\n");                             \
        ::assertFatalExit();                           \
    }

#endif
