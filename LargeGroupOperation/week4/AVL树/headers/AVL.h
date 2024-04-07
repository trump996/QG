#ifndef AVL_H
#define AVL_H

typedef struct Node {
	int value;
	struct Node* left, * right;
	int height;
}Node, * NodePtr;

void AVL_Init(NodePtr* T);
NodePtr AVL_Insert(NodePtr* T, int data);
NodePtr AVL_Delete(NodePtr* T, int data);
void AVL_Destory(NodePtr* T);
void AVL_printnode(NodePtr R);
NodePtr AVL_search(NodePtr Root, int x);
void AVL_preorderR(NodePtr Root, void (*visit)(NodePtr));
void AVL_inorderR(NodePtr Root, void (*visit)(NodePtr));
void AVL_postorderR(NodePtr Root, void (*visit)(NodePtr));
void AVL_levelOrder(NodePtr Root, void (*visit)(NodePtr));

#endif // !AVL_H

