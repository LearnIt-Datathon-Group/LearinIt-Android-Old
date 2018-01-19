//
// Created by saar eshet and  on 28/12/2017.
//

#ifndef LEARINIT_ANDROID_PROGRAMUTILITIES_H
#define LEARINIT_ANDROID_PROGRAMUTILITIES_H


#include "../models/Program.h"
#include "../models/Subject.h"
#include "../models/UserPreferences.h"
#include "../models/LessonResults.h"

class ProgramUtilities
{
public:
    static Program * createProgram(UserPreferences UserP, Subject SubjectsLeft[]);
    Program reBuildProgram(Program currentProgram, Program ProgramHistory[],
    LessonResults Data[], Subject SubjectsLeft[], Program RecommendedProgram, int ProgramHistory_Size, int Data_Size, int SubjectsLeft_Size );
};


#endif //LEARINIT_ANDROID_PROGRAMUTILITIES_H
