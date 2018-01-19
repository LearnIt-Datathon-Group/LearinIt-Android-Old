//
// Created by Roi Amiel on 23/12/2017.
//

#include "Params.h"
#include "../lib/json/json11.hpp"

#ifndef LEARNIT_MEDIA_H
#define LEARNIT_MEDIA_H

using namespace json11;
using namespace std;

class Media {
private:
    string title;
    string content;
    int time;
    int type;

public:
    Media(string JsonString);

    const string &getTitle() const;
    const string &getContent() const;
    int getTime() const;
    int getType() const;

    void setTitle(const string &title);
    void setContent(const string &content);
    void setTime(int time);
    void setType(int type);

    string toString();

    Media();
};


#endif //LEARNIT_MEDIA_H
