#################################################
## Build HappyBus/common/system ##
#################################################

# Common source files
SET( SRC_COMMON  system/os/OSMutex.hpp
                 system/os/Types.hpp
                 system/os/OSCondVar.hpp
                 system/Mutex.cpp
                 system/Mutex.hpp
                 system/CondVar.hpp
                 system/CondVar.cpp
                 system/AtomicInteger.hpp
                 system/AtomicInteger.cpp)

# Source files for POSIX
SET( SRC_POSIX
     system/posix/POSIXCondVar.cpp
     system/posix/POSIXMutex.cpp )

IF(WIN32)

ELSEIF(APPLE)
     SET (SOURCES ${SOURCES} ${SRC_COMMON} ${SRC_POSIX})
ELSE (UNIX)
     SET (SOURCES ${SOURCES} ${SRC_COMMON} ${SRC_POSIX})
ENDIF()