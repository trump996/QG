#include "AVL.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct node
{
    NodePtr data;//数据域指针
    struct node* next;//指向当前结点的下一结点
} QNode;

typedef struct Lqueue
{
    QNode* front;//队头
    QNode* rear; //队尾
} LQueue;

void Queue_Init(LQueue* Q);
int Queue_Isempty(LQueue* Q);
void Queue_EnLQueue(LQueue* Q, NodePtr treenode);
NodePtr Queue_DeLQueue(LQueue* Q);
void Queue_Destory(LQueue* Q);

#endif // !QUEUE_H