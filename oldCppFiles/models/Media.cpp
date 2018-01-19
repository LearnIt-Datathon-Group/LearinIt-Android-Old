//
// Created by Roi Amiel on 23/12/2017.
//

#include "Media.h"

Media::Media(string JsonString) {
    string error;
    Json jsonObject = Json::parse(JsonString, error);

    setTitle(jsonObject["mTitle"].string_value());
    setContent(jsonObject["mContent"].string_value());
    setTime(jsonObject["mTime"].int_value());
    setType(jsonObject["mType"].int_value());
}

const string &Media::getTitle() const {
    return title;
}

const string &Media::getContent() const {
    return content;
}

int Media::getTime() const {
    return time;
}

int Media::getType() const {
    return type;
}

void Media::setTitle(const string &title) {
    Media::title = title;
}

void Media::setContent(const string &content) {
    Media::content = content;
}

void Media::setTime(int time) {
    Media::time = time;
}

string Media::toString() {
    Json::object jsonObject;

    jsonObject["mTitle"] = getTitle();
    jsonObject["mContent"] = getContent();
    jsonObject["mTime"] = getTime();
    jsonObject["mType"] = getType();

    return Json(jsonObject).dump();
}

void Media::setType(int type) {
    Media::type = type;
}

Media::Media() {

}
