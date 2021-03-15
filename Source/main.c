#include "../Header/List.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* pStudentsData = fopen("Students.txt", "rt");

    if (pStudentsData == NULL) {
        printf("ERROR: file with data was not opened!!!");
        return -1;
    }

    SNode *pList = NULL;

    if (!InitializeList(&pList, pStudentsData)) {
        printf("ERROR: Inizialization failed\n");
        return -1;
    }

    PrintList(pList);

    int nPointsCount = 3;
    int *pStudentsPoints = FindPointsLessThenAvarageInList(pList, nPointsCount);

    if (pStudentsPoints == NULL) {
        printf("ERROR: program can't allocate an array with points\n");
        return -1;
    }

    for (int i = 0; i < nPointsCount; i++)
        RemoveNode(&pList, pStudentsPoints[i]);

    printf("\n");
    PrintList(pList);

    FreeList(&pList);
    free(pStudentsPoints);
    pStudentsPoints = NULL;
    fclose(pStudentsData);
    return 0;
}
