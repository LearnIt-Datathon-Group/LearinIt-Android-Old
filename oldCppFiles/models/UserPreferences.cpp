//
// Created by Roi Amiel on 21/12/2017.
//

#include "UserPreferences.h"

UserPreferences::UserPreferences(string JsonString) {
    string error;
    Json jsonObject = Json::parse(JsonString, error);

    //mLessonsPerWeek
    setLessonsPerWeek(jsonObject["mLessonsPerWeek"].int_value());
    //mLessonTime
    setLessonTime(jsonObject["mLessonTime"].int_value());
    //mLessonType
    setLessonType(jsonObject["mLessonType"].int_value());
    //mLessonPattern
    setLessonPattern(jsonObject["mLessonPattern"].int_value());
}

int UserPreferences::getLessonsPerWeek() const {
    return lessonsPerWeek;
}

int UserPreferences::getLessonTime() const {
    return lessonTime;
}

int UserPreferences::getLessonType() const {
    return lessonType;
}

int UserPreferences::getLessonPattern() const {
    return lessonPattern;
}

void UserPreferences::setLessonsPerWeek(int lessonsPerWeek) {
    UserPreferences::lessonsPerWeek = lessonsPerWeek;
}

void UserPreferences::setLessonTime(int lessonTime) {
    UserPreferences::lessonTime = lessonTime;
}

void UserPreferences::setLessonType(int lessonType) {
    UserPreferences::lessonType = lessonType;
}

void UserPreferences::setLessonPattern(int lessonPattern) {
    UserPreferences::lessonPattern = lessonPattern;
}

string UserPreferences::toString() {
    return std::string();
}
UserPreferences::UserPreferences() {

}
