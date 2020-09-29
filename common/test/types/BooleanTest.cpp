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
void BooleanTest::test_constructor_argumentOfTypeBool_shouldNotNull()
{
    bool base = false;
    std::auto_ptr<Boolean> booleanPtr(new Boolean(base));
    CPPUNIT_ASSERT(NULL != booleanPtr.get());
}

void BooleanTest::test_copyConstructor_aBooleanObject_shouldNotNull()
{
    bool base = false;
    Boolean boolean(base);
    std::auto_ptr<Boolean> booleanCopyPtr(new Boolean(boolean));
    CPPUNIT_ASSERT(NULL != booleanCopyPtr.get());
}

void BooleanTest::test_bool_castObjectTobool_shouldReturnMember()
{
    bool base = false;
    Boolean boolean(base);

    CPPUNIT_ASSERT_EQUAL(base, static_cast<bool>(boolean));
}

}  // namespace types
}  // namespace unittest
}  // namespace common
}  // namespace happybus
