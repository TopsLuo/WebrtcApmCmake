
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#头文件
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./../../../../../../../)
INCLUDE_DIRECTORIES(./../include)
INCLUDE_DIRECTORIES(./../../../../../../common_audio/signal_processing/include)

#define
ADD_DEFINITIONS(-DWEBRTC_ANDROID -DWEBRTC_POSIX)


#src
SET(SRC_LIST arith_routines.c
             arith_routines_hist.c
             arith_routines_logist.c
             audio_decoder_isac.cc
             audio_encoder_isac.cc
             bandwidth_estimator.c
             crc.c
             decode.c
             decode_bwe.c
             encode.c
             encode_lpc_swb.c
             entropy_coding.c
             fft.c
             filter_functions.c
             filterbank_tables.c
             filterbanks.c
             intialize.c
             isac.c
             lattice.c
             lpc_analysis.c
             lpc_gain_swb_tables.c
             lpc_shape_swb12_tables.c
             lpc_shape_swb16_tables.c
             lpc_tables.c
             pitch_estimator.c
             pitch_filter.c
             pitch_gain_tables.c
             pitch_lag_tables.c
             spectrum_ar_model_tables.c
             transform.c)

ADD_LIBRARY( webrtc_codecs_isac
             STATIC
             ${SRC_LIST})

