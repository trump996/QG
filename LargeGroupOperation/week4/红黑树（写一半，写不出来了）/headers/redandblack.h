#include <stdbool.h>

#ifndef REDANDBLACK_H
#define REDANDBLACK_H

typedef struct Node {
	int value;
	bool color;
	struct Node* left, * right;
	struct Node* parent;
}Node, * NodePtr;

void RAB_Init(NodePtr* T);
void RAB_AdjustAfterInsert(NodePtr T, NodePtr node);
NodePtr RAB_Insert(NodePtr* T, int data);
NodePtr RAB_search(NodePtr Root, int x);
void RAB_printnode(NodePtr R);
void RAB_preorderR(NodePtr Root, void (*visit)(NodePtr));
void RAB_inorderR(NodePtr Root, void (*visit)(NodePtr));
void RAB_postorderR(NodePtr Root, void (*visit)(NodePtr));
void RAB_levelOrder(NodePtr Root, void (*visit)(NodePtr));

#endif // !REDANDBLACK_H

