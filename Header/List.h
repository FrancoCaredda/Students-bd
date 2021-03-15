#ifndef LIST_H
#define LIST_H

#include "Student.h"

#include <stdio.h>

typedef struct Snode_t {
    SStudent sStudent;
    struct Snode_t* next;
} SNode;

int InitializeList(SNode **pList, FILE *pFile);
int CalculateAvarageOfStudentsPoint(SNode *pList);
int* FindPointsLessThenAvarageInList(SNode *pList, int nPointsCount);
int ListLength(SNode *pList);

void DeleteLastNode(SNode *pList);
void PrintList(SNode *pList);
void SortList(SNode *pList);
void RemoveNode(SNode **pList, int nPoint);
void FreeList(SNode **pList);

#endif