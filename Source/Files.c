#include "../Header/Files.h"
#include "../Header/defines.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//--------------------------------------------------------------------------------
static int IsStringNumer(const char *pString) {
    int nStringLength = strlen(pString);

    for (int i = 0; i < nStringLength + 1; i++) {
        if (!isdigit(pString[i])) 
            return 0;
    }

    return 1;
}
//--------------------------------------------------------------------------------
int IsFileEmpty(const char *pFileName) {
    FILE *pFile = fopen(pFileName, "rt");

    fseek(pFile, 0, SEEK_END);

    if (ftell(pFile) == 0) { 
        fclose(pFile); 
        return 1;
    }

    fclose(pFile);

    return 0;
}
//--------------------------------------------------------------------------------
int IsFileInCorrectForm(const char *pFileName) {
    FILE *pFile = fopen(pFileName, "rt");

    if (pFile == NULL)
        return NOT_CORRECT_FORM;

    char *pTemp;
    const char *pDelimeters = " /+=%%^&*()#!@~";

    char Buffer[BUFFER_SIZE] = { 0 };
    int nIndex = 0;

    while (fgets(Buffer, BUFFER_SIZE, pFile) != NULL) {
        pTemp = strtok(Buffer, pDelimeters);
        nIndex = 0;

        do {
            if ((strstr(pTemp, ".") != NULL) && (nIndex != SECOND_POSITION))
                return NOT_CORRECT_FORM;
            else if (IsStringNumer(pTemp) && (nIndex != LAST_POSITION))
                return NOT_CORRECT_FORM;
            else if (strlen(pTemp) >= STRING_SIZE)
                return STRING_BIGGER_THEN_MAX_LENGTH;

            pTemp = strtok(NULL, pDelimeters);
            nIndex++;
        } while (pTemp != NULL);

        if (feof(pFile) != 0) {
            break;
        } else if (ferror(pFile) != 0) {
            fseek(pFile, 0, SEEK_SET);
            break;
        }
    }

    fclose(pFile);

    return CORRECT_FORM;
}
//--------------------------------------------------------------------------------