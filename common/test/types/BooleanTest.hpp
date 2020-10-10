///////////////////////////////////////////////////////////////////////////////
/// @file  BooleanTest.hpp
/// @brief Declaration of BooleanTest to test happybus::common::types::Boolean
///
/// @author Hubert lehaiping@126.com
///
/// Copyright (c) 2019 XXX
/// All rights reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_TYPES_BOOLEANTEST_HPP
#define HAPPYBUS_COMMON_TYPES_BOOLEANTEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "types/Boolean.hpp"

namespace happybus
{
namespace common
{
namespace test
{
namespace types
{
class BooleanTest : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(BooleanTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testCopyConstructor);
    CPPUNIT_TEST(testCastObjectTobool);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @brief test that the constructor doesnt return a null object
     */
    void testConstructor();

    /**
     * @brief Test that the copy constructor makes a copy of the object
     */
    void testCopyConstructor();

    /**
     * @brief test that the object returns the member when casted to bool
     */
    void testCastObjectTobool();
};
}  // namespace types
}  // namespace unittest
}  // namespace common
}  // namespace happybus
#endif  // TSD_COMMON_TYPES_BOOLEANTEST_HPP.