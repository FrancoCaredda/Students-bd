#ifndef STUDENT_H
#define STUDENT_H

#include "../Header/defines.h"

typedef struct _SStudent {
    char cName[STRING_SIZE];
    char cSurname[STRING_SIZE];
    char cDateOfBirth[STRING_SIZE];

    int nPoint;
} SStudent;

int CompareStudents(SStudent *pStudent1, SStudent *pStudent2);

#endif