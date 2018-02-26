cmake_minimum_required (VERSION 2.6)

project (linearFit)

set(CMAKE_SYSTEM_NAME Linux)
set(packages ../../../../../packages)

set(CMAKE_C_COMPILER   ${packages}/clang4.0.1/bin/clang )
set(CMAKE_CXX_COMPILER ${packages}/clang4.0.1/bin/clang++ )

#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/tmp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/..)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -stdlib=libc++ -fpermissive  -fno-omit-frame-pointer  \
  -fno-optimize-sibling-calls -fno-limit-debug-info  -Wattributes  \
 -msse4.2 -Wno-padded  -Wno-float-equal  -Wno-unused-function  -Wno-unused-local-typedef  \
 -fPIC  -Wno-format-security   -fstack-protector-all  -O3 ")

set (debugCMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -stdlib=libc++ -fpermissive  -fno-omit-frame-pointer  \
  -fno-optimize-sibling-calls -fno-limit-debug-info  -Wattributes  \
 -msse4.2 -Wno-padded  -Wno-float-equal  -Wno-unused-function  -Wno-unused-local-typedef  \
 -fPIC  -Wno-format-security   -fstack-protector-all  -O1 -g ")

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories( .)
include_directories(  ${packages}/boost_1_64_0/ )

add_executable(linearFit ${SRC_FILES})

TARGET_LINK_LIBRARIES(linearFit -lpthread -lrt -lm -ldl -lc++ -lunwind  -lunwind-x86_64  
	-lboost_chrono -lboost_thread   -lboost_system  -lz 
	-Wl,-O0 -Wl,--no-whole-archive -Wl,-rpath,../../packages/boost_1_64_0/stage/lib -Wl,-rpath-link,. -Wl,-rpath,../../packages/clang4.0.1/lib )


