//
// Created by Roi Amiel on 21/12/2017.
//

#include <string>
#include "Params.h"
#include "../lib/json/json11.hpp"

using namespace json11;
using namespace std;

#ifndef LEARNIT_PROGRAM_H
#define LEARNIT_PROGRAM_H

class Program {
private:
    int lessonsPerWeek;
    int lessonTime;
    int lessonType;
    int lessonPattern;

public:
    Program();

    Program(string jsonString);
    Program(int mLessonsPerWeek, int mLessonTime, int mLessonType , int mLessonPattern);

    int getLessonsPerWeek() const;
    int getLessonTime() const;
    int getLessonType() const;
    int getLessonPattern() const;

    void setLessonsPerWeek(int lessonsPerWeek);
    void setLessonTime(int lessonTime);
    void setLessonType(int lessonType);
    void setLessonPattern(int lessonPattern);

    string toString()const;
};


#endif //LEARNIT_PROGRAM_H
