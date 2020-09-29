#################################################
## Build HappyBus/common/system ##
#################################################

# Common source files
SET( SRC_COMMON  ./system/Mutex.cpp
                 ./system/Mutex.hpp)

# Source files for POSIX
SET( SRC_POSIX
   ./system/posix/POSIXMutex.cpp )

IF(WIN32)

ELSEIF(APPLE)

ELSE (UNIX)
     SET (SOURCES ${SOURCES} ${SRC_COMMON} ${SRC_POSIX})
ENDIF()