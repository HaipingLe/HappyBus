//////////////////////////////////////////////////////////////////////
/// @file BooleanTest.cpp
/// @author Hubert lehaiping@126.com
/// @brief Unit Tests to test Boolean
///
/// Copyright (c) 2019 XXX
/// All rights reserved
//////////////////////////////////////////////////////////////////////
#include <memory>
#include "BooleanTest.hpp"

using namespace happybus::common::types;

namespace happybus
{
namespace common
{
namespace test
{
namespace types
{
void BooleanTest::testConstructor()
{
    bool base1 = true;
    std::unique_ptr<Boolean> booleanPtr1(new Boolean(base1));
    CPPUNIT_ASSERT(NULL != booleanPtr1.get());

    bool base2 = false;
    std::unique_ptr<Boolean> booleanPtr2(new Boolean(base2));
    CPPUNIT_ASSERT(NULL != booleanPtr2.get());
}

void BooleanTest::testCopyConstructor()
{
    bool base1 = true;
    Boolean boolean1(base1);
    std::unique_ptr<Boolean> booleanCopyPtr1(new Boolean(boolean1));
    CPPUNIT_ASSERT(NULL != booleanCopyPtr1.get());

    bool base2 = false;
    Boolean boolean2(base2);
    std::unique_ptr<Boolean> booleanCopyPtr2(new Boolean(boolean2));
    CPPUNIT_ASSERT(NULL != booleanCopyPtr2.get());
}

void BooleanTest::testCastObjectTobool()
{
    bool base1 = true;
    Boolean boolean1(base1);
    CPPUNIT_ASSERT_EQUAL(true, static_cast<bool>(boolean1));

    bool base2 = false;
    Boolean boolean2(base2);
    CPPUNIT_ASSERT_EQUAL(false, static_cast<bool>(boolean2));


}

}  // namespace types
}  // namespace unittest
}  // namespace common
}  // namespace happybus
