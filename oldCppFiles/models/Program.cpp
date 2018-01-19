//
// Created by Roi Amiel on 21/12/2017.
//

#include "Program.h"

Program::Program(string jsonString) {
    string error;
    Json jsonObject = Json::parse(jsonString, error);

    setLessonsPerWeek(jsonObject["mLessonsPerWeek"].int_value());
    setLessonTime(jsonObject["mLessonTime"].int_value());
    setLessonType(jsonObject["mLessonType"].int_value());
    setLessonPattern(jsonObject["mLessonPattern"].int_value());
}


int Program::getLessonsPerWeek() const {
    return lessonsPerWeek;
}

int Program::getLessonTime() const {
    return lessonTime;
}

int Program::getLessonType() const {
    return lessonType;
}

int Program::getLessonPattern() const {
    return lessonPattern;
}

void Program::setLessonsPerWeek(int lessonsPerWeek) {
    Program::lessonsPerWeek = lessonsPerWeek;
}

void Program::setLessonTime(int lessonTime) {
    Program::lessonTime = lessonTime;
}

void Program::setLessonType(int lessonType) {
    Program::lessonType = lessonType;
}

void Program::setLessonPattern(int lessonPattern) {
    Program::lessonPattern = lessonPattern;
}

string Program::toString()const {
    Json::object json;

    json["mLessonsPerWeek"] = getLessonsPerWeek();
    json["mLessonTime"] = getLessonTime();
    json["mLessonType"] = getLessonType();
    json["mLessonPattern"] = getLessonPattern();

    return Json(json).dump();
}

Program::Program(int mLessonsPerWeek, int mLessonTime, int mLessonType , int mLessonPattern)
{

}

Program::Program() {}
