#ifndef TREE_H
#define TREE_H

typedef struct Node {
	int value;
	struct Node* left, * right;
}Node, * NodePtr;

void BST_init(NodePtr* Root);
NodePtr BST_insert(NodePtr* Root, int x);
NodePtr BST_delete(NodePtr* Root, int x);
NodePtr BST_search(NodePtr Root, int x);
void BST_destory(NodePtr Root);

void BST_printnode(NodePtr R);

void BST_preorderI(NodePtr Root, void (*visit)(NodePtr));
void BST_preorderR(NodePtr Root, void (*visit)(NodePtr));
void BST_inorderI(NodePtr Root, void (*visit)(NodePtr));
void BST_inorderR(NodePtr Root, void (*visit)(NodePtr));
void BST_postorderI(NodePtr Root, void (*visit)(NodePtr));
void BST_postorderR(NodePtr Root, void (*visit)(NodePtr));
void BST_levelOrder(NodePtr Root, void (*visit)(NodePtr));

#endif // !TREE_H

