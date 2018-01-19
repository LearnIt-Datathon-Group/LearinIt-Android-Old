    //
// Created by Roi Amiel on 21/12/2017.
//

#ifndef LEARNIT_PARAMS_H
#define LEARNIT_PARAMS_H

//LESSON TYPE
#define TEXTS_LESSON_TYPE 0
#define VIDEOS_LESSON_TYPE 1
#define SOUNDS_LESSON_TYPE 2

//LESSON PATTERN
#define GROUPS_LESSON_PATTERN 0
#define MIXED_LESSON_PATTERN 1

//LESSON TIME
#define SHORT_LESSON_TIME 0
#define MEDIUM_LESSON_TIME 1
#define LONG_LESSON_TIME 2

//LESSON GRADE
#define MAX_LESSON_GRADE 100
#define MIN_LESSON_GRADE 0

#define TEXT_TYPE 0
#define VIDEO_TYPE 1
#define SOUND_TYPE 2
#define QUSTION_CHOSIE_TYPE 3
#define QUSTION_OPEN_TYPE 4

#define TIME_SPACE 180000

//CONTENT TIME
#define TEXT_WORD_CONTENT_TIME (60 * 1000 / 90)
#define CHOICE_QUESTION_CONTENT_TIME (60 * 1000)
#define OPEN_QUESTION_CONTENT_TIME (2 * 60 * 1000)
#define MEDIA_CONTENT_TIME 1.6

//Lesson lengths(Short,Medium,Long) are translated into milliseconds
#define SHORT_LESSON_MIL_S 600000
#define MEDIUEM_LESSON_MIL_S 1200000
#define LONG_LESSON_MIL_S 1800000
//Lessons Per Week
#define PER_WEEK 5
//vaild input
#define invaild_input -1
/**
 * In ms
 * */
static int wordNumberToContentTime(int WordsNumber) {
    return WordsNumber * TEXT_WORD_CONTENT_TIME;
}

static int choiceQuestionToContentTime(int WordsNumber) {
    return wordNumberToContentTime(WordsNumber) + CHOICE_QUESTION_CONTENT_TIME;
}

static int openQuestionToContentTime(int WordsNumber) {
    return wordNumberToContentTime(WordsNumber) + OPEN_QUESTION_CONTENT_TIME;
}

static int mediaToContentTime(int MS) {
    return (int) (MS * MEDIA_CONTENT_TIME);
}

class Params {

};

#endif //LEARNIT_PARAMS_H
