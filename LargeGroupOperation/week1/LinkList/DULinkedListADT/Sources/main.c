#include "..\Headers\Double_LinkedList.h"
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    SetConsoleOutputCP(65001);//解决vscode乱码问题

    printf("*****************************************************\n");
    printf("**              欢迎进入双链表管理系统             **\n");
    printf("**               您可以作出如下选择：              **\n");
    printf("**                                                 **\n");
    printf("**             1.创建一个空的双链表                **\n");
    printf("**             2.前插入新节点                      **\n");
    printf("**             3.后插入新节点                      **\n");
    printf("**             4.删除一个节点                      **\n");
    printf("**             5.销毁链表并释放所有节点            **\n");
    printf("**             6.退出系统                          **\n");
    printf("*****************************************************\n");

    int Choice,Value;
    DuLinkedList Double;
    bool State=0;//检测链表是否创建

    printf("请输入您的选择：\n");

    while(1)
    {
        scanf("%d",&Choice);

        switch (Choice)
        {
            case 1://创建空链表
            {
                if (State==0)
                {
                    InitList_DuL(&Double);
                    printf("创建完毕\n");
                    State=1;
                    printf("请再次选择您想进行的操作：\n");
                }
                else
                    printf("链表已经存在\n");
            }
            break;

            case 2://前插入
            {
                if (State==1)
                {
                    DuLNode* New=(DuLinkedList)malloc(sizeof(DuLNode));
                    New->prior=NULL;
                    New->next=NULL;

                    if(Double->next==NULL)//当前链表只有头节点
                    {
                        printf("当前链表只有头结点，不能使用前插入哦,请重新选择您想进行的操作：\n");
                    }
                    else
                    {
                        printf("请先输入您要插入的节点的位置的的后一个节点的数据：\n");
                        
                        if (scanf("%d",&Value)==1&&SearchList(Double,Value)==SUCCESS)
                        {
                            DuLinkedList Insertion=MY_SearchList(Double,Value);

                            printf("已找到这个节点，请再输入您想插入的数据：\n");
                            scanf("%d",&Value);                           
                            New->data=Value;
                            InsertBeforeList_DuL(Insertion,New);

                            printf("节点插入完毕，当前链表如下所示：\n");
                            LinkedPrint(Double);                            
                        }
                        else
                            printf("链表中没有这个节点哦，请重新选择您想要的操作：\n");
                    }
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 3://后插入
            {
                if (State==1)
                {
                    DuLNode* New=malloc(sizeof(DuLNode));
                    New->next=NULL;
                    New->prior=NULL;

                    if(Double->next==NULL)//当前链表为空
                    {
                        printf("当前链表为空，请直接输入您想插入的数据：\n");

                        scanf("%d",&Value);
                        New->data=Value;
                        InsertAfterList_DuL(Double,New);

                        printf("插入成功，当前链表如下所示：\n");
                        LinkedPrint(Double);                  
                    }
                    else//当前链表不为空
                    {
                        printf("当前链表非空，请先输入您想插入的位置的前一个节点的数据：\n");
                        if(scanf("%d",&Value)==1&&SearchList(Double,Value)==SUCCESS)
                        {
                            DuLinkedList Insertion=MY_SearchList(Double,Value);

                            printf("已经找到这个节点，请再次输入您想插入的数据：\n");
                            scanf("%d",&Value);
                            
                            New->data=Value;
                            InsertAfterList_DuL(Insertion,New);

                            printf("节点插入完毕，当前链表如下所示：\n");
                            LinkedPrint(Double);                           
                        }
                        else
                            printf("链表中没有这个节点哦，请重新选择您想要的操作：\n");
                    }
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 4://删除
            {
                if(State==1)
                {
                    int Data;
                    DuLinkedList Prev;

                    printf("请先输入你想要删除的节点的前一个节点的数据：\n");
                    if(scanf("%d",&Value)==1&&SearchList(Double,Value)==SUCCESS)
                    {
                        Prev=MY_SearchList(Double,Value);

                        DeleteList_DuL(Prev,&Data);
                        printf("删除节点完毕，当前链表如下所示\n");
                        LinkedPrint(Double);
                        printf("请再次选择你想要的操作：\n");
                    }
                    else
                        printf("没有找到这个节点哦,请重新选择你要的操作\n");
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 5://销毁
            {
                if(State==1)//链表存在
                {
                    DestroyList_DuL(&Double);
                    printf("销毁完毕\n");
                    State=0;
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 6://退出
            {
                printf("拜拜！\n");
                return 0;
            }
            break;
        
            default:
                printf("请按照要求输入操作选项对应的数字\n");
            break;
        }
    }
}