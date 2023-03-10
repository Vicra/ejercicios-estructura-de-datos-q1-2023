#include "Tree.h"

int main(int argc, char const *argv[])
{
    Tree* t = new Tree();
    t->root = t->insert(t->root, new TreeNode(10));
    t->insert(t->root, new TreeNode(5));
    t->insert(t->root, new TreeNode(15));
    t->insert(t->root, new TreeNode(3));
    t->insert(t->root, new TreeNode(13));
    t->insert(t->root, new TreeNode(20));
    // t->insert(t->root, new TreeNode(11));

    // TreeNode* mostLeft = t->mostLeftSon(t->root);
    // cout << "Hijo mas izquierdo: " << mostLeft->getValue() << "\n";

    // TreeNode* mostRight = t->mostRightSon(t->root);
    // cout << "Hijo mas derecho: " << mostRight->getValue() << "\n";

    // cout << "Preorder: " << endl;
    // t->preorder(t->root);
    // cout << endl;

    cout << "Inorder ASC: " << endl;
    t->inorder(t->root);
    cout << endl; 

    // cout << "Postorden ASC: " << endl;
    // t->postorden(t->root);
    // cout << endl << endl; 

    // cout << "Searching 2..." << endl;
    // TreeNode * searchedNode = t->search(t->root, 1);
    // if(searchedNode != nullptr) {
    //     cout << "Yes, exists" << endl;
    //     cout << "value: " <<searchedNode->getValue() << endl;
    // } else {
    //     cout << "No exists, what a shame" << endl;
    // }

    // cout << "Depth 1:" << t->depth(t->root, searchedNode, 0) << endl;
    t->print("", t->root, false);

    t->deleteNode(t->root, 15);

    t->print("", t->root, false);
    return 0;
}
