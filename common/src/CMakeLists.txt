#################################################
## Build HappyBus Common Library ##
#################################################
IF (WIN32)
	MESSAGE(STATUS "=====================Current OS is windows==========================")
ELSEIF (APPLE)
	MESSAGE(STATUS "==========Current OS is Apple system, such as macOS, iOS, tvOS or watchOS============")
ELSEIF (UNIX)
	MESSAGE(STATUS "=====================Current OS is UNIX or UNIX-like=======================")
ENDIF()


FILE( GLOB_RECURSE SOURCES
         props/*.[ch]pp
         types/*.[ch]pp
         errors/*.[ch]pp
         Assert.[ch]pp
         Compiler.hpp
         fatal.hpp
         ctassert.hpp
   )

INCLUDE ("system/system.cmake")
ADD_LIBRARY("HappyBusCommon" SHARED ${SOURCES})
