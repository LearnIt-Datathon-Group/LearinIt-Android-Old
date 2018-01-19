#include <jni.h>
#include <string>
#include "../models/Subject.h"
#include "../models/separateLessons.h"
#include "../utilities/ProgramUtilities.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_manwithandroid_learnit_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_manwithandroid_learnit_utilities_JNIUtilities_createProgram(JNIEnv *env, jclass type,
                                                                 jstring userP_,
                                                                 jstring SubjectsArray_) {
    const char *userP = env->GetStringUTFChars(userP_, 0);
    const char *SubjectsArray = env->GetStringUTFChars(SubjectsArray_, 0);

    string error;
    Json subjectsArray = Json::parse(std::string(SubjectsArray), error);
    int size = (int) subjectsArray.array_items().size();
    Subject subjects[size];
    for (int i = 0; i < size; ++i) {
        subjects[i] = Subject(subjectsArray[i].string_value());
    }

    Program* newProgram = ProgramUtilities::createProgram(UserPreferences(userP), subjects);

    env->ReleaseStringUTFChars(userP_, userP);
    env->ReleaseStringUTFChars(SubjectsArray_, SubjectsArray);

    return env->NewStringUTF(newProgram->toString().c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_manwithandroid_learnit_utilities_JNIUtilities_seperateLessons(JNIEnv *env, jclass type,
                                                                   jstring SubjectsList_,
                                                                   jstring Program_,
                                                                   jint WeeksLeft) {
    const char *SubjectsList = env->GetStringUTFChars(SubjectsList_, 0);
    const char *ProgramStr = env->GetStringUTFChars(Program_, 0);

    string error;
    Json subjectsArray = Json::parse(std::string(SubjectsList), error);
    int size = (int) subjectsArray.array_items().size();
    Subject subjects[size];
    for (int i = 0; i < size; ++i) {
        subjects[i] = Subject(subjectsArray[i].string_value());
    }

    Lesson * lessons = getSeparateLessons(subjects, size, Program(ProgramStr), 0);
    int sizeOf = sizeof(lessons) / sizeof(lessons[0]);

    Json::array array;

    for (int i = 0; i < sizeOf; ++i) {
        array.push_back(lessons[i].toString());
    }

    env->ReleaseStringUTFChars(SubjectsList_, SubjectsList);
    env->ReleaseStringUTFChars(Program_, ProgramStr);

    return env->NewStringUTF(Json(array).dump().c_str());
}