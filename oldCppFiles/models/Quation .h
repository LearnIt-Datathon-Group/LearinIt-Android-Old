//
// Created by magshimim on 26/12/2017.
//

#ifndef LEARINIT_ANDROID_QUATION_H
#define LEARINIT_ANDROID_QUATION_H

#endif //LEARINIT_ANDROID_QUATION_H

#include <string>
#include "Params.h"
#include "Subject.h"
#include "../lib/json/json11.hpp"

using namespace json11;
using namespace std;

class Question {

public:
     static final String ANSWERS_TAG = "mAnswers";
     void Question(String string);
     String[][] getAnswers();
     void setAnswers(String[][] Answers);
     String toString();

private:
     String[][] mAnswers = null;

}
