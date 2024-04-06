#include "tree.h"

#ifndef STACK_H
#define STACK_H

typedef struct StackNode
{
	NodePtr treenode;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

void Stack_Init(LinkStackPtr* top);
int Stack_Isempty(LinkStackPtr top);
void Stack_Push(LinkStackPtr* top, NodePtr data);
NodePtr Stack_Pop(LinkStackPtr* top);
NodePtr Stack_GetTop(LinkStackPtr top);
void Stack_Destory(LinkStackPtr* top);

#endif
