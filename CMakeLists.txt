cmake_minimum_required(VERSION 3.13)
project(Viakin)

set(CMAKE_CXX_COMPILER "gcc")
# set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers")

set(CMAKE_C_FLAGS_DEBUG "-ggdb")
set(CMAKE_C_FLAGS_RELEASE "-O3")

set(CMAKE_INSTALL_RPATH "/usr/local/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,/usr/local/lib")

include_directories(
	${PROJECT_SRC_DIR}/include
	${PROJECT_SRC_DIR}/src
)

find_library(RAYLIB_LIB raylib)

link_libraries(raylib X11 dl pthread m)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_executable(Harp.exe ${all_SRCS})
