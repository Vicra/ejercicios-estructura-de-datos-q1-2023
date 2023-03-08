#include "AVLTree.h"

int main()
{
	AVLTree* t = new AVLTree();
  t->root = t->insert(t->root, 10);
  t->root = t->insert(t->root, 20);
  t->root = t->insert(t->root, 30);
  t->root = t->insert(t->root, 40);
  t->root = t->insert(t->root, 50);
  t->root = t->insert(t->root, 60);
	
  // t->inorder(t->root);
  // t->print("", t->root, false);
  t->printTree(t->root, nullptr, false);

	return 0;
}
