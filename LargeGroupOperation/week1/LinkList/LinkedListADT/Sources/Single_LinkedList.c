#include "..\Headers\Single_LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Status InitList(LinkedList *L)//创建一个空链表，只有头结点没有值
{
    *L=NULL;
    return SUCCESS;
}

void DestroyList(LinkedList *L)//销毁一个链表，释放所有结点
{
    LinkedList current=*L;
    LinkedList next=NULL;

    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }

    *L=NULL;
}

Status InsertList(LNode **p, LNode *q)//在节点P之后插入节点Q
{
    if (*p==NULL)//P是头指针，q是第一个节点
    {
        *p=q;
        q->next=NULL;
    }
    else
    {
        q->next=(*p)->next;
        (*p)->next=q;
    }

    return SUCCESS;
}

Status DeleteList(LNode *p, int *e)//删除p之后的第一个节点，并将值赋给e
{
    *e=p->data;
    LNode *Delete=p->next;

    if(p==NULL)//p是表头
        p=Delete->next;
    else
        p->next=Delete->next;
        
    free(Delete);
    return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(int e))//遍历链表并调用visit函数
{
    LinkedList Current=L;

    while(Current!=NULL)
    {
        visit(Current->data);
        Current=Current->next;
    }
}

Status SearchList(LinkedList L,int e)//根据e查找第一个节点
{
    LinkedList Current=L;

    while(Current!=NULL)
    {
        if(Current->data==e)
            return SUCCESS;
        Current=Current->next;
    }
    
    return ERROR;    
}

LNode* MY_SearchList(LinkedList L,int e)//我自己再改装一个查找函数
{
    LinkedList Current=L;

    while(Current!=NULL&&Current->data!=e)
        Current=Current->next;

    return Current;
}

Status ReverseList(LinkedList *L)//反转链表
{
    if(*L==NULL)
        return ERROR;

    LinkedList Next=NULL;
    LinkedList Previous=NULL;
    LinkedList Current=*L;

    while(Current!=NULL)
    {
        Next=Current->next;
        Current->next=Previous;
        Previous=Current;
        Current=Next;
    }
    *L=Previous;

    return SUCCESS;
}

Status IsLoopList(LinkedList L)//判断链表是否循环
{
    if(L==NULL||L->next==NULL)
        return SUCCESS;//只有一个节点，没有环
    
    if(L->next==L)
        return SUCCESS;//如果链表只有一个节点，且该节点的next指针指向自己，也不成环
    
    LNode* Fast=L;
    LNode* Slow=L;

    while(Fast!=NULL&&Fast->next!=NULL)
    {
        Fast=Fast->next->next;
        Slow=Slow->next;

        if(Slow==Fast)
            return ERROR;//成环            
    }

    return SUCCESS;
}

LNode* ReverseEvenList(LinkedList *L)//翻转奇偶
{
    LinkedList P1=*L;//奇数项的起点
    LinkedList P2=P1->next;//偶数项的起点
    LinkedList P=NULL;

    *L=P2;//二节点要变成头结点
    P1->next=P2->next;//节点1指向节点3
    P2->next=P1;//节点2指向节点1
    //先把节点1和节点2换一下

    P=P1;

    while (P->next!=NULL&&P->next->next!=NULL)
    {
        P1=P->next;
        P2=P1->next;

        P->next=P2;
        P1->next=P2->next;
        P2->next=P1;

        P=P1;
    }

    return *L;
}

LNode* FindMidNode(LinkedList *L)//找到中间节点
{
    LNode* Fast=*L;
    LNode* Slow=*L;//使用快慢指针法找中间节点

    while (Fast!=NULL&&Fast->next!=NULL)
    {
        Slow=Slow->next;
        Fast=Fast->next->next;
    }
    
    return Slow;//如果个数为偶数，返回的是中间两项中后面的那一项
}

void LinkedPrint(LinkedList L)//自己再加一个函数，打印链表
{
    LinkedList Current=L;

    while(Current!=NULL)
    {
        printf("%d->",Current->data);
        Current=Current->next;
    }
    printf("NULL\n");
}