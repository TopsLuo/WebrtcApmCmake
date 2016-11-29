
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#src
SET(SRC_LIST delay_estimator.c
             delay_estimator_wrapper.c)

ADD_LIBRARY( webrtc_utility
             STATIC
             ${SRC_LIST})

