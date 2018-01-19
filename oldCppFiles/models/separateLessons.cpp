//
// Created by magshimim on 28/12/2017.
//
#include "separateLessons.h"
#include "../utilities/TimeUtilities.h"

Lesson* getSeparateLessons(Subject* subject_left, int subjects_size, Program CurrentProgram,int WeeksLeft)
{
    int i =0;
    int timeSum = 0;
    int index = 0;
    vector<Subject> subjects;

    while(timeSum < CurrentProgram.getLessonTime() && index < subjects_size)
    {
        subjects.push_back(subject_left[index]);
        timeSum += (int) getEstimatedTime(subject_left);
        index++;
    }

    Subject **array_subjects;
    *array_subjects = new Subject[subjects.size()];
    for(i=0;i<subjects.size();i++)
    {
        *array_subjects[i] = subjects[i];
    }

    Lesson *lesson = new Lesson();
    lesson->setLessonSubjects(array_subjects, subjects.size());

    return lesson;
}
