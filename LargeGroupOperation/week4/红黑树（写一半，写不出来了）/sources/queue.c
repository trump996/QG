#include "queue.h"
#include <stdlib.h>

void Queue_Init(LQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
}

int Queue_Isempty(LQueue* Q)
{
	if (Q->front == NULL)
		return 1;
	else
		return 0;
}

void Queue_EnLQueue(LQueue* Q, NodePtr treenode)
{
	if (Q == NULL)
		return;

	QNode* New = (QNode*)malloc(sizeof(QNode));
	if (New == NULL)
		return;

	New->data = treenode;
	New->next = NULL;

	if (Q->front == NULL)
		Q->front = Q->rear = New;
	else
	{
		Q->rear->next = New;
		Q->rear = New;
	}
	return;
}

NodePtr Queue_DeLQueue(LQueue* Q)
{
	if (Q == NULL)
		return NULL;

	NodePtr x = NULL;

	QNode* Temp = Q->front;
	x = Temp->data;
	Q->front = Q->front->next;

	if (Q->front == NULL)
		Q->rear = NULL;

	free(Temp);
	return x;
}

void Queue_Destory(LQueue* Q)
{
	if (Q == NULL)
		return;

	while (Q->front != NULL)
	{
		QNode* Temp = Q->front;
		Q->front = Q->front->next;

		free(Temp);
	}
}