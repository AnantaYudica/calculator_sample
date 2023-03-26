#include <stdio.h>
#include "Calculator_jni.h"
#include "Calculator.h"

static Calculator& GetInstance()
{
    static Calculator instance;
    return instance;
}

extern "C"
{

JNIEXPORT jstring JNICALL Java_com_example_app_Calculator_print ( JNIEnv *env, jobject obj )
{
    jstring value; 
    auto str = GetInstance().Print();
    value = env->NewStringUTF(str.c_str());
    return value;
}

JNIEXPORT jint JNICALL Java_com_example_app_Calculator_key ( JNIEnv *env, jobject obj, jstring str )
{
    auto size = env->GetStringUTFLength(str);
    jboolean is_copy;
    auto get_str = env->GetStringUTFChars(str, &is_copy);
    for (auto i = 0; i < size; ++i)
    {
        GetInstance().Key(get_str[i]);
    }
    if (is_copy == JNI_TRUE) 
    {
        env->ReleaseStringUTFChars(str, get_str);
    }
    return (jint)size;
}

}
