
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX -DWEBRTC_NS_FIXED)


#src
SET(SRC_LIST intelligibility_enhancer.cc
             intelligibility_utils.cc)

ADD_LIBRARY( webrtc_intelligibility
             STATIC
             ${SRC_LIST})

