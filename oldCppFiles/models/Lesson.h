//
// Created by Roi Amiel on 21/12/2017.
//

#include <string>
#include "Params.h"
#include "Subject.h"
#include "../lib/json/json11.hpp"

#ifndef LEARNIT_LESSON_H
#define LEARNIT_LESSON_H

using namespace json11;
using namespace std;

class Lesson {
private:


    Subject** lessonSubjects;
    int lessonSubjectsSize = -1;

public:
    Lesson();
    Lesson(string JsonString);

    const Subject * getLessonSubjects() const;
    int getLessonSubjectsSize() const;

    void setLessonSubjects(Subject **lessonSubjects, int Size);

    string toString()const;
};


#endif //LEARNIT_LESSON_H
