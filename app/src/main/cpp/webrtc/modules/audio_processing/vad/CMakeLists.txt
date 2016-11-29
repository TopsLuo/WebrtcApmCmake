
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWEBRTC_ANDROID -DWEBRTC_POSIX")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#src
SET(SRC_LIST gmm.cc
             pitch_based_vad.cc
             pitch_internal.cc
             pole_zero_filter.cc
             standalone_vad.cc
             vad_audio_proc.cc
             vad_circular_buffer.cc
             voice_activity_detector.cc)

ADD_LIBRARY( webrtc_vad
             STATIC
             ${SRC_LIST})

