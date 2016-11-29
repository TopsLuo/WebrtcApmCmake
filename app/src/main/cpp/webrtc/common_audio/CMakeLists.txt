
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX)

#根据当前平台来判断
if (${ANDROID_ABI} STREQUAL "armeabi-v7a")
  #neon 平台文件
  set(neon_SRCS fir_filter_neon.cc)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")
  add_definitions("-DHAVE_NEON=1" "-DWEBRTC_HAS_NEON")

elseif (${ANDROID_ABI} STREQUAL "arm64-v8a")
  #neon 平台文件
  set(neon_SRCS fir_filter_neon.cc)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")
  add_definitions("-DHAVE_NEON=1" "-DWEBRTC_HAS_NEON" "-DWEBRTC_ARCH_ARM64")

else ()
  set(neon_SRCS)
endif ()


#src
SET(SRC_LIST audio_converter.cc
             audio_ring_buffer.cc
             audio_util.cc
             blocker.cc
             channel_buffer.cc
             fft4g.c
             lapped_transform.cc
             real_fourier.cc
             real_fourier_ooura.cc
             ring_buffer.c
             sparse_fir_filter.cc
             window_generator.cc
             fir_filter.cc)

ADD_LIBRARY( webrtc_common_audio
             STATIC
             ${SRC_LIST}
             ${neon_SRCS})

