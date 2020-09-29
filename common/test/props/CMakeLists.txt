SET(TESTNAME test_props)
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/common/test/props
                     ${PROJECT_SOURCE_DIR}/common/src/
                     $(CPPUNIT_INCLUDE_DIR))

#source files
FILE( GLOB_RECURSE SOURCES
         ${PROJECT_SOURCE_DIR}/common/test/props/*.cpp)

#header files
FILE( GLOB_RECURSE HEADERS
         ${PROJECT_SOURCE_DIR}/include/*.hpp
         ${PROJECT_SOURCE_DIR}/test/*.hpp)

#build
SET (EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/Test")
add_executable (${TESTNAME} ${SOURCES} ${HEADERS})
target_link_libraries (${TESTNAME} cppunit)
add_test (NAME ${TESTNAME} COMMAND "${EXECUTABLE_OUTPUT_PATH}/${TESTNAME}")