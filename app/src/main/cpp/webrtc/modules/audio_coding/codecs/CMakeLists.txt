
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX -DWEBRTC_NS_FIXED -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__UCLIBC__)


#src
SET(SRC_LIST audio_decoder.cc
             audio_encoder.cc)

ADD_LIBRARY( webrtc_codecs
             STATIC
             ${SRC_LIST})

