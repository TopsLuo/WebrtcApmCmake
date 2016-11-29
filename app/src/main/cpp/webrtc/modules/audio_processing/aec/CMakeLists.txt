
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWEBRTC_ANDROID")


#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../)

#根据当前平台来判断
if (${ANDROID_ABI} STREQUAL "armeabi-v7a")
  #neon 平台文件
  set(neon_SRCS aec_core_neon.c
                aec_rdft_neon.c)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DHAVE_NEON=1 -DWEBRTC_HAS_NEON")

elseif (${ANDROID_ABI} STREQUAL "arm64-v8a")
  #neon 平台文件
  set(neon_SRCS aec_core_neon.c
                aec_rdft_neon.c)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DHAVE_NEON=1 -DWEBRTC_HAS_NEON -DWEBRTC_ARCH_ARM64")

else ()
  set(neon_SRCS)
endif ()


#src
SET(SRC_LIST aec_resampler.c
             echo_cancellation.c
             aec_core.c
             aec_rdft.c)

ADD_LIBRARY( webrtc_aec
             STATIC
             ${SRC_LIST}
             ${neon_SRCS})

