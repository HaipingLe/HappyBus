#################################################
## Build HappyBus/common/system ##
#################################################

# Common source files
SET( SRC_COMMON  system/os/OsMutex.hpp
                 system/os/Types.hpp
                 system/Mutex.cpp
                 system/Mutex.hpp
                 system/AtomicInteger.hpp
                 system/AtomicInteger.cpp)

# Source files for POSIX
SET( SRC_POSIX
     system/posix/POSIXMutex.cpp )

IF(WIN32)

ELSEIF(APPLE)
     SET (SOURCES ${SOURCES} ${SRC_COMMON} ${SRC_POSIX})
ELSE (UNIX)
     SET (SOURCES ${SOURCES} ${SRC_COMMON} ${SRC_POSIX})
ENDIF()