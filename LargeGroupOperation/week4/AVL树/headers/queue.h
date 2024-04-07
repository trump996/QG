#include "AVL.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct node
{
    NodePtr data;//������ָ��
    struct node* next;//ָ��ǰ������һ���
} QNode;

typedef struct Lqueue
{
    QNode* front;//��ͷ
    QNode* rear; //��β
} LQueue;

void Queue_Init(LQueue* Q);
int Queue_Isempty(LQueue* Q);
void Queue_EnLQueue(LQueue* Q, NodePtr treenode);
NodePtr Queue_DeLQueue(LQueue* Q);
void Queue_Destory(LQueue* Q);

#endif // !QUEUE_H