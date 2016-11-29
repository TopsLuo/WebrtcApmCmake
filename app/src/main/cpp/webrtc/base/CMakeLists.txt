PROJECT(WEBRTC_BASE)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../)
INCLUDE_DIRECTORIES(./../../)

#define
add_definitions(-DWEBRTC_POSIX -DWEBRTC_ANDROID -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__UCLIBC__ )

#src
SET(SRC_LIST checks.cc
             criticalsection.cc
             event.cc
             event_tracer.cc
             platform_file.cc
             platform_thread.cc
             timeutils.cc
             logging.cc
             stringencode.cc)

ADD_LIBRARY( webrtc_base
             STATIC
             ${SRC_LIST})

