#include "Tree.h"

int main(int argc, char const *argv[])
{
    Tree* t = new Tree();
    t->root = t->insert(t->root, new TreeNode(2));
    t->root = t->insert(t->root, new TreeNode(3));
    t->root = t->insert(t->root, new TreeNode(1));
    t->root = t->insert(t->root, new TreeNode(4));

    // t->preorder(t->root);
    t->print("", t->root, false);
    return 0;
}
