//
// Created by Yosef and Ori on 21/12/2017.
//

//Put functions here to help you calculate conversions in time units
#include "TimeUtilities.h"
unsigned int count_words_in_text(string text)
{
    int i = 0;
    int count = 1;
    for (i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            count++;
        }
    }
    return count;
}

long getEstimatedTime(Subject* subject,int size)
{
    int i,j;
    int sub_size;
    Subject * temp_subject;
    Media * temp_media = new Media[1];
    int type_media;
    int count_words = 0;
    long time = 0;
    for(i=0;i<size;i++)
    {
        temp_subject = &subject[i];

        if(temp_subject == nullptr) continue;

        temp_media = (Media *) temp_subject->getMediaList();
        sub_size = temp_subject->getMediaListSize();
        for(j=0;j<sub_size;j++)
        {
            type_media = temp_media[j].getType();
            if(type_media == TEXT_TYPE)
            {
                count_words = count_words_in_text(temp_media[j].getContent());
                time += wordNumberToContentTime(count_words);
            }
            else if(type_media == QUSTION_CHOSIE_TYPE)
            {
                count_words = count_words_in_text(temp_media[j].getContent());
                time += choiceQuestionToContentTime(count_words);
            }
            else if(type_media == QUSTION_OPEN_TYPE)
            {
                count_words = count_words_in_text(temp_media[j].getContent());
                time += openQuestionToContentTime(count_words);
            }
            else//sound or VIDEO
            {
                time += mediaToContentTime(temp_media[j].getTime());
            }
        }
    }
    return time;
}


long getEstimatedTime(Subject* subject)
{
    int i,j;
    int sub_size;
    Subject * temp_subject;
    Media * temp_media = new Media[1];
    int type_media;
    int count_words = 0;
    long time = 0;

    temp_media = (Media *) subject->getMediaList();
    sub_size = subject->getMediaListSize();
    for(j = 0; j < sub_size; j++)
    {
        type_media = temp_media[j].getType();
        if(type_media == TEXT_TYPE)
        {
            count_words = count_words_in_text(temp_media[j].getContent());
            time += wordNumberToContentTime(count_words);
        }
        else if(type_media == QUSTION_CHOSIE_TYPE)
        {
            count_words = count_words_in_text(temp_media[j].getContent());
            time += choiceQuestionToContentTime(count_words);
        }
        else if(type_media == QUSTION_OPEN_TYPE)
        {
            count_words = count_words_in_text(temp_media[j].getContent());
            time += openQuestionToContentTime(count_words);
        }
        else//sound or VIDEO
        {
            time += mediaToContentTime(temp_media[j].getTime());
        }
    }


    return time;
}