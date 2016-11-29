
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX)

#根据当前平台来判断
if (${ANDROID_ABI} STREQUAL "armeabi-v7a")
  #neon 平台文件
  set(neon_SRCS sinc_resampler_neon.cc)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")
  add_definitions("-DHAVE_NEON=1" "-DWEBRTC_HAS_NEON")

elseif (${ANDROID_ABI} STREQUAL "arm64-v8a")
  #neon 平台文件
  set(neon_SRCS sinc_resampler_neon.cc)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")
  add_definitions("-DHAVE_NEON=1" "-DWEBRTC_HAS_NEON" "-DWEBRTC_ARCH_ARM64")

else ()
  set(neon_SRCS)
endif ()


#src
SET(SRC_LIST push_resampler.cc
             push_sinc_resampler.cc
             resampler.cc
             sinusoidal_linear_chirp_source.cc
             sinc_resampler.cc)

ADD_LIBRARY( webrtc_common_audio_resampler
             STATIC
             ${SRC_LIST}
             ${neon_SRCS})

