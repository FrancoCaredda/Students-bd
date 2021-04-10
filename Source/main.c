#include "../Header/List.h"
#include "../Header/Files.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* pStudentsData = fopen("Students2.txt", "rt");

    if (pStudentsData == NULL) {
        printf("ERROR: file with data was not opened!!!");
        return -1;
    }

    if (IsFileEmpty("Students.txt")) {
        printf("Error file is empty\n");
        return -1;
    }

    switch (IsFileInCorrectForm("Students2.txt")) {
    case NOT_CORRECT_FORM:
        printf("ERROR file is not correct\n"\
                "Correct form: Name\t Surename\t Date of birth\t Point");

        return -1;
        break;
    case STRING_BIGGER_THEN_MAX_LENGTH:
        printf("Max string size: %d\n", STRING_SIZE - 1);
        return -1;
        break;
    }

    SNode *pList = NULL;

    if (!InitializeList(&pList, pStudentsData)) {
        printf("ERROR: Initialization failed\n");
        fclose(pStudentsData);
        return -1;
    }

    PrintList(pList);

    int nPointsCount = 3;
    int *pStudentsPoints = FindPointsLessThenAvarageInList(pList, nPointsCount);

    if (pStudentsPoints == NULL) {
        printf("ERROR: program can't allocate an array with points\n");
        FreeList(&pList);
        fclose(pStudentsData);

        return -1;
    }

    for (int i = 0; i < nPointsCount; i++)
        RemoveNode(&pList, pStudentsPoints[i]);

    printf("\n");

    if (IsListEmpty(pList)) {
        printf("\n\nList was removed\n");
        free(pStudentsPoints);
        pStudentsPoints = NULL;
        fclose(pStudentsData);
        
        return -1;
    }

    PrintList(pList);

    FreeList(&pList);
    free(pStudentsPoints);
    pStudentsPoints = NULL;
    fclose(pStudentsData);
    return 0;
}
