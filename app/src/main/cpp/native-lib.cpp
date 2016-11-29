#include <jni.h>
#include "webrtc/modules/audio_processing/include/audio_processing.h"

using namespace webrtc;
using namespace std;

jobject
Java_me_cq_webrtccmake_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject jobj,
        jobject jlist) {

    AudioProcessing *audioProcessing = AudioProcessing::Create();
    return NULL;
}
