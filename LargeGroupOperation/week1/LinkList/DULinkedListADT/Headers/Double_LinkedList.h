#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H

#define OVERFLOW -1

typedef struct DuLNode {
	int data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

Status InitList_DuL(DuLinkedList *L);
void DestroyList_DuL(DuLinkedList *L);
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
Status DeleteList_DuL(DuLNode *p, int *e);
void TraverseList_DuL(DuLinkedList L, void (*visit)(int e));
void LinkedPrint(DuLinkedList L);
Status SearchList(DuLinkedList L,int e);
DuLNode* MY_SearchList(DuLinkedList L,int e);

#endif