#include "..\Headers\Double_LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Status InitList_DuL(DuLinkedList *L)//初始化一个只有头结点的空链表
{
    *L=(DuLinkedList)malloc(sizeof(DuLNode));
    if(*L==NULL)
        return ERROR;

    (*L)->data=0;
    (*L)->prior=NULL;
    (*L)->next=NULL;

    return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L)//销毁链表
{
    if(*L==NULL)
        return;

    DuLNode *Current=(*L)->next;

    while (Current!=NULL)
    {
        DuLNode* Next=Current->next;
        free(Current);
        Current=Next;
    }

    free(*L);
    *L=NULL;
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)//在节点p之前插入节点q
{
    if(q==NULL||p==NULL)
        return ERROR;

    q->prior=p->prior;
    q->next=p;

    if(p->prior!=NULL)
        p->prior->next=q;

    p->prior=q;

    return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)//在节点p之后插入节点q
{
    if(p==NULL)
        return ERROR;

    if(q->next!=NULL||q->prior!=NULL)
        return ERROR;

    q->next=p->next;
    q->prior=p;

    if(p->next!=NULL)
        p->next->prior=q;

    p->next=q;

    return SUCCESS;
}

Status DeleteList_DuL(DuLNode *p, int *e)//删除节点p之后的第一个节点，并将值赋给e
{
    if(p==NULL||p->next==NULL)
        return ERROR;
    
    DuLinkedList Delete=p->next;//要删除的节点
    *e=Delete->data;

    p->next=Delete->next;

    if(Delete->next!=NULL)//如果删除的节点不是最后一个节点，更新其后继节点的前驱指针
        Delete->next->prior=p;
    free(Delete);

    return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(int e))//遍历链表并使用visit函数
{
    DuLinkedList Current=L->next;

    while (Current!=NULL)
    {
        visit(Current->data);
        Current=Current->next;
    }
}

void LinkedPrint(DuLinkedList L)//自己再加一个函数，打印链表
{
    DuLinkedList Current=L->next;

    while(Current!=NULL)
    {
        printf("%d<->",Current->data);
        Current=Current->next;
    }
    printf("NULL\n");
}

Status SearchList(DuLinkedList L,int e)//根据e查找第一个节点
{
    DuLinkedList Current=L->next;

    while(Current!=NULL)
    {
        if(Current->data==e)
            return SUCCESS;
        Current=Current->next;
    }
    
    return ERROR;    
}

DuLNode* MY_SearchList(DuLinkedList L,int e)//我自己再改装一个查找函数
{
    DuLinkedList Current=L->next;

    while(Current!=NULL&&Current->data!=e)
        Current=Current->next;

    return Current;
}