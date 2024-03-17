#ifndef SINGLE_LINKEDLIST_H
#define SINGLE_LINKEDLIST_H

typedef struct LNode {
	int data;
  	struct LNode *next;
} LNode, *LinkedList;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status InitList(LinkedList *L);
void DestroyList(LinkedList *L);
Status InsertList(LNode **p, LNode *q);
Status DeleteList(LNode *p, int *e);
void TraverseList(LinkedList L, void (*visit)(int e));
Status SearchList(LinkedList L,int e);
LNode* MY_SearchList(LinkedList L,int e);
Status ReverseList(LinkedList *L);
Status IsLoopList(LinkedList L);
LNode* ReverseEvenList(LinkedList *L);
LNode* FindMidNode(LinkedList *L);
void LinkedPrint(LinkedList L);

#endif