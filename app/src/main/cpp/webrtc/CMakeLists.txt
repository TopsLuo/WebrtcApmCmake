PROJECT(WEBRTC)

cmake_minimum_required(VERSION 3.4.1)

#添加webrtc aec
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/aec)
#添加webrtc aecm
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/aecm)
#添加webrtc agc
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/agc)
#添加webrtc ns
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/ns)
#添加webrtc utility
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/utility)
#添加webrtc vad
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/vad)
#添加webrtc apm
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing)
#添加webrtc intelligibility
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/intelligibility)
#添加webrtc transient
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/transient)
#添加webrtc beamformer
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_processing/beamformer)
#添加webrtc common vad
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/common_audio/vad)
#添加webrtc common vad
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/common_audio/signal_processing)
#添加webrtc common vad
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/common_audio)
#添加webrtc common resampler
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/common_audio/resampler)
#添加webrtc common isac
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_coding/codecs/isac/main/source)
#添加webrtc common codecs
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/modules/audio_coding/codecs)
#添加webrtc common resampler
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/system_wrappers/source)
#添加webrtc common base
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/base)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWEBRTC_POSIX -DWEBRTC_ANDROID")


add_library( webrtc
             STATIC
             empty.cpp)

target_link_libraries( webrtc
                       webrtc_aec
                       webrtc_aecm
                       webrtc_agc
                       webrtc_ns
                       webrtc_utility
                       webrtc_vad
                       webrtc_apm
                       webrtc_intelligibility
                       webrtc_transient
                       webrtc_beamformer
                       webrtc_common_audio_vad
                       webrtc_common_audio
                       webrtc_common_audio_resampler
                       webrtc_codecs_isac
                       webrtc_system_wrapper
                       webrtc_base)