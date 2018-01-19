//
// Created by Roi Amiel on 21/12/2017.
//

#include <string>
#include "Params.h"
#include "../lib/json/json11.hpp"

#ifndef LEARNIT_USERPREFERENCES_H
#define LEARNIT_USERPREFERENCES_H

using namespace json11;
using namespace std;

class UserPreferences {
private:
    int lessonsPerWeek;
    int lessonTime;
    int lessonType;
    int lessonPattern;

public:
    UserPreferences();
    UserPreferences(string JsonString);

    int getLessonsPerWeek() const;
    int getLessonTime() const;
    int getLessonType() const;
    int getLessonPattern() const;

    void setLessonsPerWeek(int lessonsPerWeek);
    void setLessonTime(int lessonTime);
    void setLessonType(int lessonType);
    void setLessonPattern(int lessonPattern);

    string toString();
};


#endif //LEARNIT_USERPREFERENCES_H
