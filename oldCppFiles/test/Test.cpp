#include <jni.h>
#include <cstdlib>
#include "../models/Media.h"
#include "../models/Program.h"
#include "../models/Subject.h"
#include "../models/Lesson.h"
#include "../models/LessonResults.h"
#include "../JavaPipelines.h"
#include "../utilities/ProgramUtilities.h"
#include "../models/separateLessons.h"
#include "../lib/json/json11.hpp"
#include "../utilities/ProgramUtilities.h"

using namespace json11;
using namespace std;

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);

extern "C"
JNIEXPORT jstring JNICALL
Java_manwithandroid_learnit_utilities_JNIUtilities_testCpp(
        JNIEnv *env,
        jclass type,
        jstring string_) {

    /*
     * DON'T DELETE!!!!!!!
     *
     * Use this function as your main
     * To run select the cppTestDebug in build variants
     * Remove this file from your local git
     *
    */

    //Add your test code here
    const char *string = env->GetStringUTFChars(string_, 0);

    LessonResults * lessonResults = new LessonResults(string);
    lessonResults->setTime(3);
    lessonResults->setEstimatedTime(5);
    lessonResults->setGrade(5);
    lessonResults->setStartTime(5);

    env->ReleaseStringUTFChars(string_, string);

    return env->NewStringUTF(lessonResults->toString().c_str());
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    std::string newString;
    newString.reserve(str.length());  // avoids a few memory allocations

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while(std::string::npos != (findPos = str.find(from, lastPos)))
    {
        newString.append(str, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }

    // Care for the rest after last occurrence
    newString += str.substr(lastPos);

    str.swap(newString);

    return str;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_manwithandroid_learnit_utilities_JNIUtilities_programTest(JNIEnv *env, jclass type, jstring Program_) {
    const char *string = env->GetStringUTFChars(Program_, 0);

    Program * program = new Program(string);
    JavaPipelines * javaPipelines = new JavaPipelines();

    program = javaPipelines->testprogramFunction(program);

    env->ReleaseStringUTFChars(Program_, string);

    return env->NewStringUTF(program->toString().c_str());
}