//
// Created by saar eshet and omer ben shimon 28/12/2017.
//
#include <time.h>
#include <stdlib.h>
#include "ProgramUtilities.h"
#define VectorArrSize 6
#define progVarsStep 0.5
#define prolongedGradeChangeTurnPoint 17

#define goodProlongedChange 0
#define badProlongedChange 1
#define goodDrasticChange 2
#define badDrasticChange 3
#define goodAvregeChange 4
#define badAvregeChange 5

vector<int> *getGradeTurnPoints(int grades[], int size);
#include "../models/UserPreferences.h"
#include "../models/Subject.h"
#include "TimeUtilities.h"
Program * ProgramUtilities::createProgram(UserPreferences UserP, Subject SubjectsLeft[])
{
    int SubjectsSize = 0;
    long SubjectTime = 0;
    SubjectsSize = sizeof(SubjectsLeft)/ sizeof(SubjectsLeft[0]);
    Program *myP = new Program();
    myP->setLessonsPerWeek(UserP.getLessonsPerWeek());
    if(UserP.getLessonTime()==SHORT_LESSON_TIME)
    {
        myP->setLessonTime(SHORT_LESSON_MIL_S);
    }
    if(UserP.getLessonTime()==MEDIUM_LESSON_TIME)
    {
        myP->setLessonTime(MEDIUEM_LESSON_MIL_S);
    }
    if(UserP.getLessonTime()==LONG_LESSON_TIME)
    {
        myP->setLessonTime(LONG_LESSON_MIL_S);
    }
    if(myP->getLessonsPerWeek()==invaild_input)
    {
        SubjectTime  = getEstimatedTime(SubjectsLeft,SubjectsSize)/myP->getLessonsPerWeek();
        myP->setLessonTime(SubjectTime);
    }
    if(myP->getLessonTime()==invaild_input)
    {
        SubjectTime = getEstimatedTime(SubjectsLeft,SubjectsSize)/myP->getLessonTime();
        myP->setLessonTime(SubjectTime);
    }
    myP->setLessonType(UserP.getLessonType());
    myP->setLessonPattern(UserP.getLessonPattern());
    return &(*myP);
}

Program ProgramUtilities::reBuildProgram(Program currentProgram, Program *ProgramHistory,
    LessonResults *Data, Subject *SubjectsLeft, Program RecommendedProgram,
    int ProgramHistory_Size, int Data_Size, int SubjectsLeft_Size ) {

    int mLessonPerWeek = 0;
    int mLessonTime = 0;
    int mLessonType = 0;
    int mLessonPattern = 0;
    //////////////////////////////////////////////////////////////
    Program* lastProg;
    Program* currProg;
    vector<int>* gradeTurningPoints;
    int* grades = new int[Data_Size];
    int goodPattern[2];
    int goodType[3];
    int badType[3];
    /////////Lesson results Data vars
    int grade = 0;
    int estimatedTime = 0;
    int time = 0;
    int startTime = 0;

 ///   Program lessonProgram(0,0,0,0); ///

    int lastGrade = -1;
    //////// program Data vars
    int lessonsPerWeek = 0;
    int lessonTime = 0;
    int lessonType;
    int lessonPattern;

    for (int i = 0; i < Data_Size; ++i) {
        grades[i] = Data[i].getGrade();
    }
    gradeTurningPoints = getGradeTurnPoints(grades, Data_Size);



       int lessonDiff = 0;
       int timeDiff = 0;
       int i = 0;

    for (std::vector<int>::iterator it = gradeTurningPoints[badDrasticChange].begin();
         it != gradeTurningPoints[badDrasticChange].end(); ++it)
    {
        lastProg = &ProgramHistory[--(*it)];
        currProg = &ProgramHistory[*it];

        lessonDiff = currProg->getLessonsPerWeek() - lastProg->getLessonsPerWeek();
        mLessonPerWeek += currProg->getLessonsPerWeek() - (lessonDiff*progVarsStep);

        timeDiff = currProg->getLessonTime() - lastProg->getLessonTime();
        mLessonTime = currProg->getLessonTime() - (timeDiff*progVarsStep);

        if(currProg->getLessonPattern() != lastProg->getLessonPattern())
        {
            goodPattern[currProg->getLessonPattern()]++;
        }
        if(currProg->getLessonType() != lastProg->getLessonType())
        {
            goodType[currProg->getLessonType()]++;
            badType[lastProg->getLessonType()]++;
        }

        i++;
    }

    mLessonPerWeek /= i;
    mLessonTime /= i;

    if(goodPattern[0] < goodPattern[1])
    {
        mLessonPattern = 1;
    }

    int lastGoodValue = 0;
    int lastBadValue = 0;
    for (int i = 1; i < 3; ++i) {
        if(goodType[lastGoodValue] < goodType[i]) {
            lastGoodValue = i;
        }
        if(badType[lastBadValue] < badType[i])
        {
            lastBadValue = i;
        }
    }

    //todo add srand
    while(mLessonType != lastBadValue)
    {
        mLessonType = rand() % 3;
    }

    /////////////////////////////////////////////////////////////
    goodPattern[0,1] = 0;
    goodType[0,1,2] = 0;
    badType[0,1,2] = 0;
    int mLessonPerWeek2 = 0;
    int mLessonTime2 = 0;
    for (std::vector<int>::iterator it = gradeTurningPoints[goodDrasticChange].begin();
         it != gradeTurningPoints[goodDrasticChange].end(); ++it)
    {
        lastProg = &ProgramHistory[--(*it)];
        currProg = &ProgramHistory[*it];

        lessonDiff = currProg->getLessonsPerWeek() - lastProg->getLessonsPerWeek();
        mLessonPerWeek += currProg->getLessonsPerWeek() + (lessonDiff*progVarsStep);

        timeDiff = currProg->getLessonTime() - lastProg->getLessonTime();
        mLessonTime = currProg->getLessonTime() + (timeDiff*progVarsStep);
        ////
        if(currProg->getLessonPattern() != lastProg->getLessonPattern())
        {
            goodPattern[lastProg->getLessonPattern()]++;
        }
        if(currProg->getLessonType() != lastProg->getLessonType())
        {
            goodType[lastProg->getLessonType()]++;
            badType[currProg->getLessonType()]++;
        }

        i++;
    }
    mLessonPerWeek2 /= i;
    mLessonTime2 /= i;
    mLessonPerWeek = (mLessonPerWeek + mLessonPerWeek2)/2;
    mLessonTime = (mLessonTime + mLessonTime2)/2;
    if(goodPattern[0] < goodPattern[1])
    {
        mLessonPattern = 1;
    }
    /////////////////////////////////////////////////////////////
    return Program(mLessonPerWeek, mLessonTime, mLessonType, mLessonPattern);
}

vector<int> *getGradeTurnPoints(int *grades, int size) {
    vector<int> result[VectorArrSize];

    int gradesSum = 0;
    int subSum = 0;
    int averages[size];
    for (int i = 0; i < size; ++i) {
        gradesSum += grades[i];
    }
    int prolongedGradeChange = 0;
    int lastGrade = 0;
    int Grade = 0;
    int gradeChange = 0;
    int percentGradeChange = 0;
    for (int i = 0; i < size; ++i) {
        subSum += grades[i];
        averages[i] = (gradesSum - subSum)/(size - i);
        Grade = grades[i];
        gradeChange = Grade - lastGrade;
        percentGradeChange = lastGrade - (lastGrade/100)*15;
        prolongedGradeChange += Grade - lastGrade;
        lastGrade = Grade;

        if(percentGradeChange > 15)
        {
            result[goodDrasticChange].insert(result[goodDrasticChange].end(), i);
        }
        else if(percentGradeChange < -15)
        {
            result[badDrasticChange].insert(result[badDrasticChange].end(), i);
        }


        if(prolongedGradeChange > prolongedGradeChangeTurnPoint)
        {
            result[goodProlongedChange].insert(result[goodDrasticChange].end(), i);
        }
        else if(prolongedGradeChange < -prolongedGradeChangeTurnPoint)
        {
            result[badProlongedChange].insert(result[badDrasticChange].end(), i);
        }

    }
    int currAverage = 0;
    int lastAverage = 0;
    int averageStep = 0;
    bool flagA, flagB = 0;
    for (int i = 0; i < size; ++i) {
        currAverage = averages[i];
        averageStep = currAverage - lastAverage;
        if(averageStep > 0){
            if(flagA) {
                if(flagB) {
                    result[goodAvregeChange].insert(result[goodAvregeChange].end(), i - 2);
                    flagA, flagB = false;
                }
                flagB = true;
            }
            flagA = true;
        }
        else{
            flagA, flagB = false;
        }

        if(averageStep < 0){
            if(flagA) {
                if(flagB) {
                    result[badAvregeChange].insert(result[badAvregeChange].end(), i - 2);
                    flagA, flagB = false;
                }
                flagB = true;
            }
        flagA = true;
    }
    else{
        flagA, flagB = false;
    }
        lastAverage = currAverage;
    }
    return result;

}