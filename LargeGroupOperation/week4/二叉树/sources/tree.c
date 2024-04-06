#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "stack.h"
#include "Queue.h"

void BST_init(NodePtr* Root)
{
	*Root = NULL;
	return;
}

NodePtr BST_search(NodePtr Root, int x)
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

NodePtr BST_insert(NodePtr* Root, int x)
{
	if ((*Root) == NULL)
	{
		*Root = (NodePtr)malloc(sizeof(Node));
		if (*Root == NULL)
			return NULL;
		else
		{
			(*Root)->value = x;
			(*Root)->left = NULL;
			(*Root)->right = NULL;
		}
	}
	else if (x < (*Root)->value)
		(*Root)->left = BST_insert(&(*Root)->left, x);
	else if (x > (*Root)->value)
		(*Root)->right = BST_insert(&(*Root)->right, x);

	return *Root;
}

NodePtr BST_delete(NodePtr* Root, int x)
{
	NodePtr Temp;

	if (*Root == NULL)
		return NULL;
	else
	{
		if (x < (*Root)->value)
			(*Root)->left = BST_delete(&(*Root)->left, x);
		else if (x > (*Root)->value)
			(*Root)->right = BST_delete(&(*Root)->right, x);
		else
		{
			if ((*Root)->left != NULL && (*Root)->right != NULL)
			{
				for (Temp = (*Root)->right; Temp->left != NULL; Temp = Temp->left);
				(*Root)->value = Temp->value;
				(*Root)->right = BST_delete(&(*Root)->right, (*Root)->value);
			}
			else
			{
				Temp = *Root;
				if ((*Root)->left == NULL)
					*Root = (*Root)->right;
				else if ((*Root)->right == NULL)
					*Root = (*Root)->left;
				free(Temp);
			}
		}
	}
	return *Root;
}

void BST_destory(NodePtr Root)
{
	NodePtr Temp;
	if (Root != NULL)
	{
		Temp = Root->right;
		BST_destory(Root->left);
		free(Root);
		BST_destory(Temp);
	}
}

void BST_printnode(NodePtr R)
{
	printf("%d  ", R->value);
	return;
}

void BST_preorderI(NodePtr Root ,void (*visit)(NodePtr))//预序遍历非递归
{
	LinkStackPtr Temp;
	Stack_Init(&Temp);

	NodePtr Current = Root;

	while (Current!=NULL || Stack_Isempty(Temp)==0)
	{
		if (Current != NULL)
		{
			visit(Current);
			Stack_Push(&Temp, Current->right);
			Stack_Push(&Temp, Current->left);

			Current = Stack_Pop(&Temp);
		}
		else
			Current = Stack_Pop(&Temp);
	}

	Stack_Destory(&Temp);
	return;
}

void BST_preorderR(NodePtr Root, void (*visit)(NodePtr))//预序遍历递归版
{
	if (Root == NULL)
		return;

	visit(Root);
	BST_preorderR(Root->left, visit);
	BST_preorderR(Root->right, visit);
}

void BST_inorderI(NodePtr Root, void (*visit)(NodePtr))//有序遍历非递归
{
	LinkStackPtr Temp;
	NodePtr Current=NULL;

	Stack_Init(&Temp);
	Stack_Push(&Temp,Root);

	while (Stack_Isempty(Temp)==0)
	{
		while ((Current = Stack_GetTop(Temp)) != NULL)
			Stack_Push(&Temp, Current->left);

		Stack_Pop(&Temp);

		if (Stack_Isempty(Temp) == 0)
		{
			Current = Stack_Pop(&Temp);
			visit(Current);
			Stack_Push(&Temp, Current->right);
		}
	}
	Stack_Destory(&Temp);
	return;
}

void BST_inorderR(NodePtr Root, void (*visit)(NodePtr))//有序遍历递归版
{
	if (Root == NULL)
		return;

	BST_inorderR(Root->left, visit);
	visit(Root);
	BST_inorderR(Root->right, visit);
}

void BST_postorderI(NodePtr Root, void (*visit)(NodePtr))//后序遍历非递归
{
	LinkStackPtr Temp;
	NodePtr Current = Root;
	Stack_Init(&Temp);

	while (Current->right != NULL)
		Current = Current->right;
	int max = Current->value;//先找到最大值
	Current = Root;
	while (Current->left != NULL)
		Current = Current->left;
	int min = Current->value;//先找到最小值

	Current = Root;//归位
	int* StateArray = (int*)malloc((max-min+1) * sizeof(int));
	for (int i = 0; i < max; i++)
		StateArray[i] = 0;

	while (Current!=NULL || Stack_Isempty(Temp)==0)
	{
		while (Current != NULL)
		{
			StateArray[Current->value - min] = 0;
			Stack_Push(&Temp, Current);
			Current = Current->left;
		}
		Current = Stack_Pop(&Temp);

		if (StateArray[Current->value - min] == 0)
		{
			StateArray[Current->value - min] = 1;
			Stack_Push(&Temp, Current);
			Current = Current->right;
		}
		else
		{
			visit(Current);
			Current = NULL;
		}
	}

	free(StateArray);
	Stack_Destory(&Temp);
	return;
}

void BST_postorderR(NodePtr Root, void (*visit)(NodePtr))//后序遍历递归版
{
	if (Root == NULL)
		return;

	BST_postorderR(Root->left, visit);
	BST_postorderR(Root->right, visit);
	visit(Root);
}

void BST_levelOrder(NodePtr Root, void (*visit)(NodePtr))//层序遍历
{
	LQueue Temp;
	Queue_Init(&Temp);
	
	if(Root!=NULL)
		Queue_EnLQueue(&Temp, Root);

	NodePtr Current = NULL;

	while (Queue_Isempty(&Temp)==0)
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