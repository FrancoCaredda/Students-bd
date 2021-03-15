#ifndef STUDENT_H
#define STUDENT_H

#define N 30

typedef struct _SStudent {
    char cName[N];
    char cSurname[N];
    char cDateOfBirth[N];

    int nPoint;
} SStudent;

int CompareStudents(SStudent *pStudent1, SStudent *pStudent2);

#endif