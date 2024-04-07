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
		temp->left->parent = x;//这个temp->left指的是移到x右边去的那个
	
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
		temp->right->parent = x;//这个temp->left指的是移到x左边去的那个

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

	node->color = 0;//新插入的节点默认标红

	while (node!=T && node->parent->color==0)
	{
		if (node->parent == node->parent->parent->left)//父亲在左边
		{
			NodePtr uncle = node->parent->parent->right;//那叔叔就在右边
			if (uncle != NULL && uncle->color == 0)//叔叔是红色的
			{
				node->parent->color = 1;//爸爸变黑
				uncle->color = 1;//叔叔变黑
				node->parent->parent = 0;//爷爷变红
				node = node->parent->parent;//把爷爷当成插入节点继续回溯
			}
			else//叔叔是黑色的
			{
				if (node == node->parent->right)//父亲在左边，但是我在右边
				{
					node = node->parent;
					Single_TurnLeft(&T, node);
				}
				node->color = 1;//爸爸变黑
				node->parent->parent = 0;//爷爷变红
				Single_TurnRight(&T, node->parent->parent);
			}
		}
		else//父亲在右边
		{
			NodePtr uncle = node->parent->parent->left;//那叔叔就在左边
			if (uncle != NULL && uncle->color == 0)//叔叔是红色的
			{
				node->parent->color = 1;//爸爸变黑
				uncle->color = 1;//叔叔变黑
				node->parent->parent = 0;//爷爷变红
				node = node->parent->parent;//把爷爷当成插入节点继续回溯
			}
			else//叔叔是黑色的
			{
				if (node == node->parent->left)//父亲在右边，但是我在左边
				{
					node = node->parent;
					Single_TurnRight(&T, node);
				}
				node->color = 1;//爸爸变黑
				node->parent->parent = 0;//爷爷变红
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

void RAB_preorderR(NodePtr Root, void (*visit)(NodePtr))//预序遍历递归版
{
	if (Root == NULL)
		return;

	visit(Root);
	RAB_preorderR(Root->left, visit);
	RAB_preorderR(Root->right, visit);
}

void RAB_inorderR(NodePtr Root, void (*visit)(NodePtr))//有序遍历递归版
{
	if (Root == NULL)
		return;

	RAB_inorderR(Root->left, visit);
	visit(Root);
	RAB_inorderR(Root->right, visit);
}

void RAB_postorderR(NodePtr Root, void (*visit)(NodePtr))//后序遍历递归版
{
	if (Root == NULL)
		return;

	RAB_postorderR(Root->left, visit);
	RAB_postorderR(Root->right, visit);
	visit(Root);
}

void RAB_levelOrder(NodePtr Root, void (*visit)(NodePtr))//层序遍历
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