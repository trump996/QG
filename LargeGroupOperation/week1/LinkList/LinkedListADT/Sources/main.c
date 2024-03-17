#include "..\Headers\Single_LinkedList.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>//vscode出现乱码问题，查阅资料得知要加上这一个头文件

int main(void)
{
    SetConsoleOutputCP(65001);//vscode出现乱码问题，查阅资料得知要加上这一条语句

    printf("*****************************************************\n");
    printf("**              欢迎进入单链表管理系统             **\n");
    printf("**               您可以作出如下选择：              **\n");
    printf("**                                                 **\n");
    printf("**             1.创建一个空的单链表                **\n");
    printf("**             2.插入新节点                        **\n");
    printf("**             3.删除一个节点                      **\n");
    printf("**             4.根据您输入的值查找节点            **\n");
    printf("**             5.反转链表                          **\n");
    printf("**             6.判断您的链表是否成环              **\n");
    printf("**             7.奇偶项翻转                        **\n");
    printf("**             8.寻找中间节点                      **\n");
    printf("**             9.销毁链表并释放所有节点            **\n");
    printf("**            10.退出系统                          **\n");
    printf("*****************************************************\n");

    int Choice,Value;
    LinkedList Single;
    bool State=0;//检测链表是否创建

    printf("请输入您的选项：\n");
    
    while(1)
    {
        scanf("%d",&Choice);
        switch (Choice)
        {
            case 1://创建一个空的单链表
            {
                if (State==0)
                {
                    InitList(&Single);
                    printf("创建完毕\n");
                    State=1;
                }
                else
                    printf("链表已经存在\n");
            }
            break;

            case 2://插入
            {
                LNode* New=(LinkedList)malloc(sizeof(LNode));

                if(State==1)//链表存在
                {
                    if(Single==NULL)//当前链表为空
                    {
                        printf("*****当前链表是空的，请直接输入您想插入的数据：*****\n");
                        scanf("%d",&Value);
                        New->data=Value;
                        InsertList(&Single,New);
                        
                        printf("插入节点完毕，当前链表如下：\n");
                        LinkedPrint(Single);
                        printf("请再次选择你想要的操作：\n");                     
                    }
                    else//链表不为空
                    {
                        LinkedList Prev;
                        printf("*****当前链表不是空的，请先输入您想在其后面插入的节点的数据：*****\n");

                        if(scanf("%d",&Value)==1&&SearchList(Single,Value)==SUCCESS)
                        {
                            Prev=MY_SearchList(Single,Value);

                            printf("*****请再输入想要插入的数据：*****\n");
                            scanf("%d",&Value);
                            New->data=Value;
                            InsertList(&Prev,New);

                            printf("插入节点完毕，当前链表如下：\n");
                            LinkedPrint(Single);
                            printf("请再次选择你想要的操作：\n");                          
                        }
                        else
                            printf("没有找到这个节点哦，请重新选择你要的操作\n");
                    }
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 3://删除
            {
                if(State==1)
                {
                    int Data;
                    LinkedList Prev;

                    printf("请先输入你想要删除的节点的前一个节点的数据：\n");
                    if(scanf("%d",&Value)==1&&SearchList(Single,Value)==SUCCESS)
                    {
                        Prev=MY_SearchList(Single,Value);

                        DeleteList(Prev,&Data);
                        printf("删除节点完毕，当前链表如下所示\n");
                        LinkedPrint(Single);
                        printf("请再次选择你想要的操作：\n");
                    }
                    else
                        printf("没有找到这个节点哦,请重新选择你要的操作\n");
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 4://查找
            {
                if(State==1)
                {
                    printf("请先输入您想要查找的节点的数据：\n");
                    scanf("%d",&Value);
                                       
                    if(SearchList(Single,Value)==SUCCESS)
                        printf("链表中存在这个节点，请重新选择你要的操作\n");
                    else
                        printf("没有找到这个节点哦,请重新选择你要的操作\n");                                    
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 5://反转整个链表
            {
                if(State==1)
                {
                    ReverseList(&Single);
                    printf("反转节点完毕，当前链表如下所示\n");
                    LinkedPrint(Single);
                    printf("请再次选择你想要的操作：\n");
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 6://是否成环
            {
                if(IsLoopList(Single)==SUCCESS)
                    printf("链表不成环\n");
                else
                    printf("链表成环\n");
            }
            break;

            case 7://奇偶反转
            {
                if(State==1)
                {
                    ReverseEvenList(&Single);
                    printf("奇偶反转完毕，当前链表如下所示\n");
                    LinkedPrint(Single);
                    printf("请再次选择你想要的操作：\n");
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 8://找中点
            {
                if(State==1)
                {
                    LNode* Mid=FindMidNode(&Single);
                    printf("链表中点的值为：%d\n",Mid->data);
                    printf("请再次选择你想要的操作：\n");
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 9://销毁
            {
                if(State==1)//链表存在
                {
                    DestroyList(&Single);
                    printf("销毁完毕\n");
                    State=0;
                }
                else
                    printf("老弟你链表呢老弟\n");
            }
            break;

            case 10://退出
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