//
// Created by Roi Amiel on 21/12/2017.
//

#include "Lesson.h"

Lesson::Lesson() {

}
Lesson::Lesson(string jsonString) {
    string error;
    Json jsonObject = Json::parse(jsonString, error);

    int subjectsSize = (int) jsonObject["mLessonSubjects"].array_items().size();

    Subject** subjects = new Subject*[subjectsSize];
    for (int i = 0; i < subjectsSize; i++) {
        string subject = jsonObject["mLessonSubjects"][i].string_value();

        subjects[i] = new Subject(subject);
    }

    setLessonSubjects(subjects, subjectsSize);
}

const Subject *Lesson::getLessonSubjects() const {
    return *lessonSubjects;
}

int Lesson::getLessonSubjectsSize() const {
    return lessonSubjectsSize;
}

void Lesson::setLessonSubjects(Subject **subjects, int size) {
    lessonSubjects = subjects;
    lessonSubjectsSize = size;
}

string Lesson::toString()const {
    Json::object jsonObject;
    Json::array subjectsArray;

    for (int i = 0; i < lessonSubjectsSize; i++) {
        subjectsArray.push_back(lessonSubjects[i]->toString());
    }

    jsonObject["mLessonSubjects"] = subjectsArray;

    return Json(jsonObject).dump();
}
