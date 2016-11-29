
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX -DWEBRTC_NS_FIXED)


#src
SET(SRC_LIST click_annotate.cc
             file_utils.cc
             moving_moments.cc
             transient_detector.cc
             transient_suppressor.cc
             wpd_node.cc
             wpd_tree.cc)

ADD_LIBRARY( webrtc_transient
             STATIC
             ${SRC_LIST})

