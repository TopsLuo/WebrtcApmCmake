
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWEBRTC_ANDROID -DWEBRTC_POSIX")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#src
SET(SRC_LIST agc.cc
             agc_manager_direct.cc
             histogram.cc
             utility.cc
             legacy/analog_agc.c
             legacy/digital_agc.c)

ADD_LIBRARY( webrtc_agc
             STATIC
             ${SRC_LIST})

