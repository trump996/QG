#include "stack.h"
#include <stdlib.h>

void Stack_Init(LinkStackPtr* top)
{
	*top = NULL;
	return;
}

int Stack_Isempty(LinkStackPtr top)
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

void Stack_Push(LinkStackPtr* top,NodePtr treenode)
{
	LinkStackPtr New = (LinkStackPtr)malloc(sizeof(StackNode));
	if (New == NULL)
		return;

	New->treenode = treenode;
	New->next = *top;
	*top = New;

	return;
}

NodePtr Stack_Pop(LinkStackPtr* top)
{
	NodePtr x;

	LinkStackPtr Temp = *top;
	x = Temp->treenode;
	*top = Temp->next;

	free(Temp);
	return x;
}

NodePtr Stack_GetTop(LinkStackPtr top)
{
	if (top == NULL)
		return NULL;
	else
		return top->treenode;
}

void Stack_Destory(LinkStackPtr* top)
{
	LinkStackPtr Current = *top;

	while (Current!=NULL)
	{
		LinkStackPtr next = Current->next;
		free(Current);
		Current = Current->next;
	}
	*top = NULL;
}