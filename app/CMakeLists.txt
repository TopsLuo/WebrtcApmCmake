PROJECT(NATIVE-LIB)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWEBRTC_POSIX -DWEBRTC_ANDROID")

include_directories(${PROJECT_SOURCE_DIR}/src/main/cpp)

ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/main/cpp/webrtc)

add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp )

target_link_libraries( native-lib
                       log
                       webrtc)
