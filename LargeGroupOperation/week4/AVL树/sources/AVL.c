#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int GetHeight(NodePtr P)
{
	if (P == NULL)
		return 0;
	else
		return P->height;
}

NodePtr Single_TurnLeft(NodePtr up)
{
	NodePtr down = up->right;
	up->right = down->left;
	down->left = up;

	up->height = ((GetHeight(up->left) > GetHeight(up->right)) ? GetHeight(up->left) : GetHeight(up->right))+1;
	down->height = ((GetHeight(down->left) > GetHeight(down->right)) ? GetHeight(down->left) : GetHeight(down->right))+1;

	return down;
}

NodePtr Single_TurnRight(NodePtr up)
{
	NodePtr down = up->left;
	up->left = down->right;
	down->right = up;

	up->height = ((GetHeight(up->left) > GetHeight(up->right)) ? GetHeight(up->left) : GetHeight(up->right)) + 1;
	down->height = ((GetHeight(down->left) > GetHeight(down->right)) ? GetHeight(down->left) : GetHeight(down->right)) + 1;

	return down;
}

/*
	up表示失衡节点
	如果是在失衡节点左孩子的右子树插入
	那就先对失衡节点的左孩子左转
	然后对失衡节点右转
*/
NodePtr Double_TurnLeftRight(NodePtr up)
{
	up->left = Single_TurnLeft(up->left);
	return Single_TurnRight(up);
}

/*
	up表示失衡节点
	如果是在失衡节点右孩子的左子树插入
	那就先对失衡节点的右孩子右转
	然后对失衡节点左转
*/
NodePtr Double_TurnRightLeft(NodePtr up)
{
	up->right = Single_TurnRight(up->right);
	return Single_TurnLeft(up);
}

void AVL_Init(NodePtr* T)
{
	*T = NULL;
	return;
}

NodePtr AVL_Insert(NodePtr* T, int data)
{
	if (*T == NULL)
	{
		*T = (NodePtr)malloc(sizeof(Node));
		(*T)->value = data;
		(*T)->height = 1;
		(*T)->left = NULL;
		(*T)->right = NULL;

		return *T;
	}
	else
	{
		if (data < (*T)->value)
		{
			(*T)->left = AVL_Insert(&(*T)->left, data);
			if (GetHeight((*T)->left) - GetHeight((*T)->right) == 2)
			{
				if (data < (*T)->left->value)
					*T = Single_TurnRight(*T);
				else
					*T = Double_TurnLeftRight(*T);
			}
		}
		else if (data > (*T)->value)
		{
			(*T)->right = AVL_Insert(&(*T)->right, data);
			if (GetHeight((*T)->right) - GetHeight((*T)->left) == 2)
			{
				if (data > (*T)->right->value)
					*T = Single_TurnLeft(*T);
				else
					*T = Double_TurnRightLeft(*T);
			}
		}
	}

	if (*T == NULL)
		return NULL;

	(*T)->height= ((GetHeight((*T)->left) > GetHeight((*T)->right)) ? GetHeight((*T)->left) : GetHeight((*T)->right)) + 1;
	return *T;
}

NodePtr AVL_Delete(NodePtr* T, int data)
{
	if (*T == NULL)
		return NULL;
	else
	{
		if (data < (*T)->value)
			(*T)->left = AVL_Delete(&(*T)->left, data);
		else if (data > (*T)->value)
			(*T)->right = AVL_Delete(&(*T)->right, data);
		else
		{
			if ((*T)->left != NULL && (*T)->right != NULL)//有两个孩子
			{
				NodePtr Temp = (*T)->right;
				while (Temp->left != NULL)
					Temp = Temp->left;

				(*T)->value = Temp->value;
				(*T)->right = AVL_Delete(&(*T)->right, Temp->value);
			}
			else//只有一个孩子或者没有孩子
			{
				NodePtr Temp = *T;

				if ((*T)->left == NULL)
				{
					*T = (*T)->right;
					free(Temp);
				}
				else if ((*T)->right == NULL)
				{
					*T = (*T)->left;
					free(Temp);
				}
				else
					free(Temp);
			}
		}

		if (*T == NULL)
			return NULL;

		(*T)->height = ((GetHeight((*T)->left) > GetHeight((*T)->right)) ? GetHeight((*T)->left) : GetHeight((*T)->right)) + 1;

		if (GetHeight((*T)->left) - GetHeight((*T)->right) == 2)
		{
			if (GetHeight((*T)->left->left) - GetHeight((*T)->left->right) == 1)
				Single_TurnRight(*T);
			else
				Double_TurnLeftRight(*T);

		}

		if (GetHeight((*T)->right) - GetHeight((*T)->left) == 2)
		{
			if (GetHeight((*T)->right->right) - GetHeight((*T)->right->left) == 1)
				Single_TurnLeft(*T);
			else
				Double_TurnRightLeft(*T);
		}
	}
	return *T;
}

void AVL_Destory(NodePtr* T)
{
	if (*T == NULL)
		return;

	AVL_Destory(&(*T)->left);
	AVL_Destory(&(*T)->right);
	free(*T);
}

void AVL_printnode(NodePtr R)
{
	printf("%d  ", R->value);
	return;
}

NodePtr AVL_search(NodePtr Root, int x)
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

void AVL_preorderR(NodePtr Root, void (*visit)(NodePtr))//预序遍历递归版
{
	if (Root == NULL)
		return;

	visit(Root);
	AVL_preorderR(Root->left, visit);
	AVL_preorderR(Root->right, visit);
}

void AVL_inorderR(NodePtr Root, void (*visit)(NodePtr))//有序遍历递归版
{
	if (Root == NULL)
		return;

	AVL_inorderR(Root->left, visit);
	visit(Root);
	AVL_inorderR(Root->right, visit);
}

void AVL_postorderR(NodePtr Root, void (*visit)(NodePtr))//后序遍历递归版
{
	if (Root == NULL)
		return;

	AVL_postorderR(Root->left, visit);
	AVL_postorderR(Root->right, visit);
	visit(Root);
}

void AVL_levelOrder(NodePtr Root, void (*visit)(NodePtr))//层序遍历
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