#include "../Header/List.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------------------------------------
// This function initialize list with data from pFile file.
// Return 1 if list inizialize was sucess else return 0
int InitializeList(SNode **pList, FILE *pFile) {
    *pList = (SNode*)malloc(sizeof(SNode));

    if (*pList == NULL)
        return 0;

    if (pFile == NULL)
        return 0;

    SNode *pCurrentElement = *pList;
    SNode *pElement = NULL;

    while (fscanf(pFile, "%s %s %s %d",
            &pCurrentElement->sStudent.cName,
            &pCurrentElement->sStudent.cSurname,
            &pCurrentElement->sStudent.cDateOfBirth,
            &pCurrentElement->sStudent.nPoint) != EOF) {
        
        if (feof(pFile) != 0) {
            break;
        } else if (ferror(pFile) != 0) {
            printf("ERROR OF READING FILE!!!\n");
            fseek(pFile, 0, SEEK_SET);
            break;
        }

        pElement = (SNode*)malloc(sizeof(SNode));
        
        if (pElement == NULL)
            return 0;

        pElement->next = NULL;
        pCurrentElement->next = pElement;
        pCurrentElement = pCurrentElement->next;
    }

    return 1;
}
//--------------------------------------------------------------------------------
void DeleteLastNode(SNode *pList) {
    SNode *pCurrentElement = pList, *pPreviousElement = NULL;

    while (pCurrentElement->next != NULL) {
        pPreviousElement = pCurrentElement;
        pCurrentElement = pCurrentElement->next;
    }

    free(pCurrentElement);
    pPreviousElement->next = NULL;
}
//--------------------------------------------------------------------------------
int ListLength(SNode* pList) {
    SNode *pCurrentElement = pList;
    int nLength = 0;

    while (pCurrentElement != NULL) {
        nLength++;
        pCurrentElement = pCurrentElement->next;
    }

    return nLength;
}
//--------------------------------------------------------------------------------
void PrintList(SNode *pList) {
    SNode *pCurrentElement = pList;

    printf("%-15s %-15s %-15s %-15s\n", "Name", "Surname", "Date of birth", 
            "Exam point");

    while (pCurrentElement != NULL) {
        printf("%-15s %-15s %-15s %-15d\n", 
            pCurrentElement->sStudent.cName,
            pCurrentElement->sStudent.cSurname,
            pCurrentElement->sStudent.cDateOfBirth,
            pCurrentElement->sStudent.nPoint);

        pCurrentElement = pCurrentElement->next;
    }
}
//--------------------------------------------------------------------------------
void FreeList(SNode **pList) {
    SNode *pCurrentElement = *pList, 
          *pTemp;

    while (pCurrentElement != NULL) {
        pTemp = pCurrentElement->next;
        free(pCurrentElement);
        pCurrentElement = pTemp;
    }

    *pList = NULL;
}
//--------------------------------------------------------------------------------
void RemoveNode(SNode **pList, int nPoint) {
    SNode *pCurrentElement = *pList, *pPrevious = NULL;
    SNode *pTemp = NULL;

    while ((pCurrentElement->sStudent.nPoint != nPoint) && (pCurrentElement != NULL)) {
        pPrevious = pCurrentElement;
        pCurrentElement = pCurrentElement->next;
    }

    if (pCurrentElement == NULL)
        return;

    if (CompareStudents(&(*pList)->sStudent, &pCurrentElement->sStudent) == 1) {
        pTemp = (*pList)->next;
        free(*pList);

        *pList = pTemp;

        return;
    }

    pTemp = pCurrentElement->next;
    free(pCurrentElement);

    pPrevious->next = pTemp;
}
//--------------------------------------------------------------------------------
int CalculateAvarageOfStudentsPoint(SNode *pList) {
    SNode *pCurrentElement = pList;
    int nSum = 0, nCountOfElements = 0;

    while (pCurrentElement != NULL) {
        nSum += pCurrentElement->sStudent.nPoint;
        nCountOfElements++;

        pCurrentElement = pCurrentElement->next;
    }

    return (nSum / nCountOfElements);
}
//--------------------------------------------------------------------------------
//This function return array with students points what less then avarage of students points
//If array wasn't allocated function returns NULL else return pointer on array allocated in heap
int* FindPointsLessThenAvarageInList(SNode *pList, int nPointsCount) {
    SNode *pCurrentElement = pList;

    int *pStudentsPoints = (int*)malloc(nPointsCount * sizeof(int));

    if (pStudentsPoints == NULL)
        return NULL;

    int nAvaragePoint = CalculateAvarageOfStudentsPoint(pList);

    int i = 0;
    while (pCurrentElement != NULL) {
        if (pCurrentElement->sStudent.nPoint < nAvaragePoint) {
           pStudentsPoints[i] = pCurrentElement->sStudent.nPoint;
           i++; 
        }

        pCurrentElement = pCurrentElement->next;
    }

    return pStudentsPoints;
}