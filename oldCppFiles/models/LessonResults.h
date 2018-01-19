//
// Created by Roi Amiel on 21/12/2017.
//

#include "Params.h"
#include "Program.h"
#include "Lesson.h"
#include "../lib/json/json11.hpp"

#ifndef LEARNIT_LESSONRESULTS_H
#define LEARNIT_LESSONRESULTS_H

using namespace json11;
using namespace std;

class LessonResults {
private:


    int time;
    int startTime;
    int estimatedTime;
    int grade;
    Program* program = nullptr;
    Lesson* lesson = nullptr;

public:
    LessonResults();

    LessonResults(string JsonString);

    int getTime() const;
    int getStartTime() const;
    int getEstimatedTime() const;
    int getGrade() const;
    const Program &getProgram() const;
    const Lesson &getLesson() const;

    void setTime(int time);
    void setStartTime(int startTime);
    void setEstimatedTime(int estimatedTime);
    void setGrade(int grade);
    void setProgram(Program *program);
    void setLesson(Lesson *lesson);

    string toString();
};

#endif //LEARNIT_LESSONRESULTS_H
