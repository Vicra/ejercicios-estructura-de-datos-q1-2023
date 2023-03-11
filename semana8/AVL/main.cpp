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

  t->print(t->root);

  t->root = t->deleteNode(t->root, 40);
	
  t->print(t->root);

	return 0;
}
