
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWEBRTC_ANDROID -DWEBRTC_POSIX -DWEBRTC_NS_FIXED")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./include)
INCLUDE_DIRECTORIES(./../../../)

ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX -DWEBRTC_NS_FIXED)

#src
SET(SRC_LIST audio_buffer.cc
             audio_processing_impl.cc
             echo_cancellation_impl.cc
             echo_control_mobile_impl.cc
             gain_control_for_experimental_agc.cc
             gain_control_impl.cc
             high_pass_filter_impl.cc
             level_estimator_impl.cc
             noise_suppression_impl.cc
             processing_component.cc
             rms_level.cc
             splitting_filter.cc
             three_band_filter_bank.cc
             typing_detection.cc
             voice_detection_impl.cc)

ADD_LIBRARY( webrtc_apm
             STATIC
             ${SRC_LIST})