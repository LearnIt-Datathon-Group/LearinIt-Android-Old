//
// Created by Roi Amiel on 21/12/2017.
//

#include <string>
#include "Params.h"
#include "Media.h"
#include "../lib/json/json11.hpp"

#ifndef LEARNIT_SUBJECT_H
#define LEARNIT_SUBJECT_H

using namespace json11;
using namespace std;

class Subject {
private:
    string subjectTitle;
    string subSubjectTitle;
    Media** mediaList = nullptr;
    long mediaListSize = -1;

    //todo add quations

public:
    Subject();

    Subject(string JsonString);

    const string &getSubjectTitle() const;
    const string &getSubSubjectTitle() const;
    Media **getMediaList() const;
    int getMediaListSize() const;

    void setMediaList(Media **mediaList, int Size);
    void setSubjectTitle(const string &subjectTitle);
    void setSubSubjectTitle(const string &subSubjectTitle);

    string toString();
};


#endif //LEARNIT_SUBJECT_H
