#include "../Header/Student.h"

#include <string.h>

int CompareStudents(SStudent *pStudent1, SStudent *pStudent2)
{
    const int condition = (strcmp(pStudent1->cName, pStudent2->cName)) == 0 &&
        (strcmp(pStudent1->cSurname, pStudent2->cSurname) == 0) &&
        (strcmp(pStudent1->cDateOfBirth, pStudent2->cDateOfBirth) == 0) &&
        (pStudent1->nPoint == pStudent2->nPoint);

    if (condition)
        return 1;

    return 0;
}