
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX -DWEBRTC_NS_FIXED)


#src
SET(SRC_LIST aligned_malloc.cc
             file_impl.cc
             logging.cc
             metrics_default.cc
             rw_lock.cc
             rw_lock_posix.cc
             trace_impl.cc
             trace_posix.cc)

ADD_LIBRARY( webrtc_system_wrapper
             STATIC
             ${SRC_LIST})

