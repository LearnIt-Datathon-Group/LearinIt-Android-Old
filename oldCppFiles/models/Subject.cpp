//
// Created by Roi Amiel on 21/12/2017.
//

#include "Subject.h"

Subject::Subject(string JsonString) {
    string error;
    Json jsonObject = Json::parse(JsonString, error);

    setSubjectTitle(jsonObject["mSubjectTitle"].string_value());
    setSubSubjectTitle(jsonObject["mSubSubjectTitle"].string_value());

    //using array
    mediaListSize = jsonObject["mMediaList"].array_items().size();
    mediaList = new Media*[mediaListSize];
    for(int i = 0; i < mediaListSize; i++)
    {
        mediaList[i] = new Media(jsonObject["mMediaList"][i].string_value());
    }

    //todo add questions values
}

const string &Subject::getSubjectTitle() const {
    return subjectTitle;
}

const string &Subject::getSubSubjectTitle() const {
    return subSubjectTitle;
}

Media **Subject::getMediaList() const {
    return mediaList;
}

int Subject::getMediaListSize() const {
    return mediaListSize;
}

void Subject::setSubjectTitle(const string &subjectTitle) {
    Subject::subjectTitle = subjectTitle;
}

void Subject::setSubSubjectTitle(const string &subSubjectTitle) {
    Subject::subSubjectTitle = subSubjectTitle;
}

void Subject::setMediaList(Media **mediaList, int Size) {
    Subject::mediaList = mediaList;
    Subject::mediaListSize = Size;
}

string Subject::toString() {
    Json::object jsonObject;
    Json::array mediaJsonArray;

    jsonObject["mSubjectTitle"] = getSubjectTitle();
    jsonObject["mSubSubjectTitle"] = getSubSubjectTitle();

    for (int i = 0; i < mediaListSize; i++) {
        mediaJsonArray.push_back(mediaList[i]->toString());
    }

    jsonObject["mMediaList"] = mediaJsonArray;

    return Json(jsonObject).dump();
}

Subject::Subject() {}

