#include "redandblack.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void Single_TurnLeft(NodePtr* T, NodePtr x)
{
	if (x == NULL || *T==NULL)
		return;

	NodePtr temp = x->right;
	x->right = temp->left;

	if (temp->left != NULL)
		temp->left->parent = x;//���temp->leftָ�����Ƶ�x�ұ�ȥ���Ǹ�
	
	temp->parent = x->parent;

	if (x->parent == NULL)
		*T = temp;
	else
	{
		if (x == x->parent->left)
			x->parent->left = temp;
		else
			x->parent->right = temp;
	}

	temp->left = x;
	x->parent = temp;
}

void Single_TurnRight(NodePtr* T,NodePtr x)
{
	if (x == NULL || *T==NULL)
		return;

	NodePtr temp = x->left;
	x->left = temp->right;

	if (temp->right != NULL)
		temp->right->parent = x;//���temp->leftָ�����Ƶ�x���ȥ���Ǹ�

	temp->parent = x->parent;

	if (x->parent == NULL)
		*T = temp;
	else
	{
		if (x == x->parent->left)
			x->parent->left = temp;
		else
			x->parent->right = temp;
	}

	temp->right = x;
	x->parent = temp;
}

void RAB_Init(NodePtr* T)
{
	*T = NULL;
	return;
}

void RAB_AdjustAfterInsert(NodePtr T, NodePtr node)
{
	if (node == NULL)
		return;

	node->color = 0;//�²���Ľڵ�Ĭ�ϱ��

	while (node!=T && node->parent->color==0)
	{
		if (node->parent == node->parent->parent->left)//���������
		{
			NodePtr uncle = node->parent->parent->right;//����������ұ�
			if (uncle != NULL && uncle->color == 0)//�����Ǻ�ɫ��
			{
				node->parent->color = 1;//�ְֱ��
				uncle->color = 1;//������
				node->parent->parent = 0;//үү���
				node = node->parent->parent;//��үү���ɲ���ڵ��������
			}
			else//�����Ǻ�ɫ��
			{
				if (node == node->parent->right)//��������ߣ����������ұ�
				{
					node = node->parent;
					Single_TurnLeft(&T, node);
				}
				node->color = 1;//�ְֱ��
				node->parent->parent = 0;//үү���
				Single_TurnRight(&T, node->parent->parent);
			}
		}
		else//�������ұ�
		{
			NodePtr uncle = node->parent->parent->left;//������������
			if (uncle != NULL && uncle->color == 0)//�����Ǻ�ɫ��
			{
				node->parent->color = 1;//�ְֱ��
				uncle->color = 1;//������
				node->parent->parent = 0;//үү���
				node = node->parent->parent;//��үү���ɲ���ڵ��������
			}
			else//�����Ǻ�ɫ��
			{
				if (node == node->parent->left)//�������ұߣ������������
				{
					node = node->parent;
					Single_TurnRight(&T, node);
				}
				node->color = 1;//�ְֱ��
				node->parent->parent = 0;//үү���
				Single_TurnLeft(&T, node->parent->parent);
			}
		}
	}
	T->color = 1;
}

NodePtr RAB_Insert(NodePtr* T,int data)
{
	if (*T == NULL)
	{
		*T = (NodePtr)malloc(sizeof(Node));
		(*T)->value = data;
		(*T)->color = 0;
		(*T)->left = NULL;
		(*T)->right = NULL;
		(*T)->parent = NULL;
		return *T;
	}

	if (data < (*T)->value)
	{
		(*T)->left = RAB_Insert(&(*T)->left, data);
		(*T)->left->parent = *T;
	}
	else

	{
		(*T)->right = RAB_Insert(&(*T)->right, data);
		(*T)->right->parent = *T;
	}

	RAB_AdjustAfterInsert(*T, (*T)->left);
	RAB_AdjustAfterInsert(*T, (*T)->right);

	return *T;
}

NodePtr RAB_search(NodePtr Root, int x)
{
	if (Root == NULL)
		return NULL;

	NodePtr Current = Root;

	while (Current != NULL)
	{
		if (x < Current->value)
			Current = Current->left;
		else if (x > Current->value)
			Current = Current->right;
		else
			break;
	}
	return Current;
}

void RAB_printnode(NodePtr R)
{
	printf("%d  ", R->value);
	return;
}

void RAB_preorderR(NodePtr Root, void (*visit)(NodePtr))//Ԥ������ݹ��
{
	if (Root == NULL)
		return;

	visit(Root);
	RAB_preorderR(Root->left, visit);
	RAB_preorderR(Root->right, visit);
}

void RAB_inorderR(NodePtr Root, void (*visit)(NodePtr))//��������ݹ��
{
	if (Root == NULL)
		return;

	RAB_inorderR(Root->left, visit);
	visit(Root);
	RAB_inorderR(Root->right, visit);
}

void RAB_postorderR(NodePtr Root, void (*visit)(NodePtr))//��������ݹ��
{
	if (Root == NULL)
		return;

	RAB_postorderR(Root->left, visit);
	RAB_postorderR(Root->right, visit);
	visit(Root);
}

void RAB_levelOrder(NodePtr Root, void (*visit)(NodePtr))//�������
{
	LQueue Temp;
	Queue_Init(&Temp);

	if (Root != NULL)
		Queue_EnLQueue(&Temp, Root);

	NodePtr Current = NULL;

	while (Queue_Isempty(&Temp) == 0)
	{
		Current = Queue_DeLQueue(&Temp);
		visit(Current);

		if (Current->left != NULL)
			Queue_EnLQueue(&Temp, Current->left);

		if (Current->right != NULL)
			Queue_EnLQueue(&Temp, Current->right);
	}

	Queue_Destory(&Temp);
	return;
}