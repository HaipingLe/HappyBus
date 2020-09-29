///////////////////////////////////////////////////////////////////////////////
/// @file  BooleanTest.hpp
/// @brief Declaration of IsSameTest to test happybus::common::pros::IsSame
///
/// @author Hubert lehaiping@126.com
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_TYPES_IsSame_HPP
#define HAPPYBUS_COMMON_TYPES_IsSame_HPP

#include <cppunit/extensions/HelperMacros.h>

#include "props/IsSame.hpp"

namespace happybus
{
namespace common
{
namespace test
{
namespace props
{
class IsSameTest : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(IsSameTest);
    CPPUNIT_TEST(test_isSame);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_isSame();

};

}
}
}
}
#endif