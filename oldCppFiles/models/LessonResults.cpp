//
// Created by Roi Amiel on 21/12/2017.
//

#include "LessonResults.h"

LessonResults::LessonResults()
{
    time = 0;
    startTime = 0;
    estimatedTime = 0;
    grade = 0;
    Program* program = nullptr;
    Lesson* lesson = nullptr;
}

LessonResults::LessonResults(string JsonString) {
    string error;
    Json jsonObject = Json::parse(JsonString, error);

    setTime(jsonObject["mTime"].int_value());
    setStartTime(jsonObject["mStartTime"].int_value());
    setEstimatedTime(jsonObject["mEstimatedTime"].int_value());
    setGrade(jsonObject["mGrade"].int_value());
    setProgram(new Program(jsonObject["mProgram"].string_value()));
    setLesson(new Lesson(jsonObject["mLesson"].string_value()));
}

int LessonResults::getTime() const {
    return time;
}

int LessonResults::getStartTime() const {
    return startTime;
}

int LessonResults::getEstimatedTime() const {
    return estimatedTime;
}

int LessonResults::getGrade() const {
    return grade;
}

const Program &LessonResults::getProgram() const {
    return *program;
}

const Lesson &LessonResults::getLesson() const {
    return *lesson;
}

void LessonResults::setTime(int time) {
    LessonResults::time = time;
}

void LessonResults::setStartTime(int startTime) {
    LessonResults::startTime = startTime;
}

void LessonResults::setEstimatedTime(int estimatedTime) {
    LessonResults::estimatedTime = estimatedTime;
}

void LessonResults::setGrade(int grade) {
    LessonResults::grade = grade;
}

void LessonResults::setProgram(Program *program) {
    LessonResults::program = program;
}

void LessonResults::setLesson(Lesson *lesson) {
    LessonResults::lesson = lesson;
}

string LessonResults::toString() {
    Json::object jsonObject;

    jsonObject["mTime"] = getTime();
    jsonObject["mStartTime"] = getStartTime();
    jsonObject["mEstimatedTime"] = getEstimatedTime();
    jsonObject["mGrade"] = getGrade();
    jsonObject["mProgram"] = getProgram().toString();
    jsonObject["mLesson"] = getLesson().toString();

    return Json(jsonObject).dump();
}