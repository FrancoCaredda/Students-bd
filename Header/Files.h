#ifndef FILES_H
#define FILES_H

enum WordsPositions {
    START_POSITION = 0,
    FIRST_POSITION = 1,
    SECOND_POSITION = 2,
    LAST_POSITION = 3
};

enum ErrorsType {
    CORRECT_FORM = 0,
    NOT_CORRECT_FORM = 1,
    STRING_BIGGER_THEN_MAX_LENGTH = 2
};

//--------------------------------------------------------------------------------
int IsFileInCorrectForm(const char *pFileName);
//--------------------------------------------------------------------------------
int IsFileEmpty(const char *pFileName);
//--------------------------------------------------------------------------------


#endif