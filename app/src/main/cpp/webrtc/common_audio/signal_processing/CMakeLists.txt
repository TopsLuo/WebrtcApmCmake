
PROJECT(SLP)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./include)
INCLUDE_DIRECTORIES(./../../../)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX)

#根据当前平台来判断
if (${ANDROID_ABI} STREQUAL "armeabi")
  #arm 平台文件
  set(neon_SRCS cross_correlation.c
                downsample_fast.c
                min_max_operations.c
                filter_ar_fast_q12.c
                spl_sqrt_floor_arm.S
                complex_bit_reverse_arm.S)

elseif (${ANDROID_ABI} STREQUAL "armeabi-v7a")
  #neon 平台文件
  set(neon_SRCS cross_correlation_neon.c
                downsample_fast_neon.c
                min_max_operations_neon.c
                filter_ar_fast_q12_armv7.S
                spl_sqrt_floor_arm.S
                complex_bit_reverse_arm.S)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")
  add_definitions("-DHAVE_NEON=1" "-DWEBRTC_HAS_NEON")

elseif (${ANDROID_ABI} STREQUAL "arm64-v8a")
  #neon 平台文件
  set(neon_SRCS cross_correlation_neon.c
                downsample_fast_neon.c
                min_max_operations_neon.c
                filter_ar_fast_q12.c
                spl_sqrt_floor.c
                complex_bit_reverse.c)

  set_property(SOURCE ${neon_SRCS}
               APPEND_STRING PROPERTY COMPILE_FLAGS " -mfpu=neon")
  add_definitions("-DHAVE_NEON=1" "-DWEBRTC_HAS_NEON" "-DWEBRTC_ARCH_ARM64")

else ()
  set(neon_SRCS)
endif ()


#src
SET(SRC_LIST auto_corr_to_refl_coef.c
             auto_correlation.c
             complex_fft.c
             copy_set_operations.c
             division_operations.c
             dot_product_with_scale.c
             energy.c
             filter_ar.c
             filter_ma_fast_q12.c
             get_hanning_window.c
             get_scaling_square.c
             ilbc_specific_functions.c
             levinson_durbin.c
             randomization_functions.c
             real_fft.c
             refl_coef_to_lpc.c
             resample.c
             resample_48khz.c
             resample_by_2.c
             resample_by_2_internal.c
             resample_fractional.c
             spl_init.c
             spl_sqrt.c
             splitting_filter.c
             sqrt_of_one_minus_x_squared.c
             vector_scaling_operations.c)

ADD_LIBRARY( webrtc_common_audio_sp
             STATIC
             ${SRC_LIST}
             ${neon_SRCS})

