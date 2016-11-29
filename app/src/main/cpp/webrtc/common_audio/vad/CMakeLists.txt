
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX)


#src
SET(SRC_LIST vad.cc
             vad_core.c
             vad_filterbank.c
             vad_gmm.c
             vad_sp.c
             webrtc_vad.c)

ADD_LIBRARY( webrtc_common_audio_vad
             STATIC
             ${SRC_LIST})

