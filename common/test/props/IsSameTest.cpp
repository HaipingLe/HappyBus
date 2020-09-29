//////////////////////////////////////////////////////////////////////
/// @file BooleanTest.cpp
/// @author Hubert lehaiping@126.com
/// @brief Unit Tests to test IsSame
///
/// Copyright (c) 2019 XXX
/// All rights reserved
//////////////////////////////////////////////////////////////////////

#include "IsSameTest.hpp"

namespace happybus
{
namespace common
{
namespace test
{
namespace props
{
void IsSameTest::test_isSame()
{
    CPPUNIT_ASSERT_EQUAL(1, static_cast<int>(happybus::common::props::is_same<std::string, std::string>::value));

    CPPUNIT_ASSERT_EQUAL(1, static_cast<int>(happybus::common::props::is_same<int, int>::value));

    CPPUNIT_ASSERT_EQUAL(1, static_cast<int>(happybus::common::props::is_same<float, float>::value));

    CPPUNIT_ASSERT_EQUAL(0, static_cast<int>(happybus::common::props::is_same<float, int>::value));

    CPPUNIT_ASSERT_EQUAL(0, static_cast<int>(happybus::common::props::is_same<std::string, float>::value));
}
}
}
}
}