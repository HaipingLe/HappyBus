////////////////////////////////////////////////////////////////////////////////
/// @file assert.cpp
///
/// @author Hubert lehaiping@126.com
///
/// @brief  Implementation of assert marcos
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include "Assert.hpp"

void assertFatalExit()
{
    std::cerr.flush();
    std::abort();
}