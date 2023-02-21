#include <iostream>
#include "TreeNode.h"

using namespace std;

class Tree
{
private:
public:
    TreeNode* root;
    Tree(/* args */);
    ~Tree();

    TreeNode* insert(TreeNode *currentRoot, TreeNode* newNode);

    void preorder(TreeNode* root);
    void print(string prefix, TreeNode* root, bool isLeft);
};

Tree::Tree(/* args */)
{
}

Tree::~Tree()
{
}

inline TreeNode *Tree::insert(TreeNode *currentRoot, TreeNode *newNode)
{
    // dinamic root is empty
    if(currentRoot == nullptr) {
        return newNode;
    }
    else if(newNode->getValue() < currentRoot->getValue()){
        // insert on left side
        currentRoot->left = insert(currentRoot->left, newNode);
    }
    else if (newNode->getValue() > currentRoot->getValue()){
        // insert on right side
        currentRoot->right = insert(currentRoot->right, newNode);
    }
    return currentRoot;
}

inline void Tree::preorder(TreeNode *currentRoot)
{
    if(currentRoot != nullptr) {
        cout << currentRoot->getValue() << " ";
        preorder(currentRoot->left);
        preorder(currentRoot->right);
    }
}

inline void Tree::print(string prefix, TreeNode *currentRoot, bool isLeft)
{
    if( currentRoot != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << currentRoot->getValue() << endl;

        // enter the next tree level - left and right branch
        print( prefix + (isLeft ? "│   " : "    "), currentRoot->left, true);
        print( prefix + (isLeft ? "│   " : "    "), currentRoot->right, false);
    } else {
        cout << prefix;
        cout << (isLeft ? "├─" : "└─" );
        cout << "nil" << endl;
    }
}
