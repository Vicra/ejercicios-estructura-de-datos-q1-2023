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

    TreeNode* mostLeftSon(TreeNode* root);
    TreeNode* mostRightSon(TreeNode* root);

    // print algorithms
    void preorder(TreeNode* root);
    void inorder(TreeNode* root);
    void postorden(TreeNode* root);

    void print(string prefix, TreeNode* root, bool isLeft);
    // search
    TreeNode* search(TreeNode* root, int key);
    int depth(TreeNode* root, TreeNode* node, int interations);
};

Tree::Tree(/* args */)
{
}

Tree::~Tree()
{
}

// search(5)
inline TreeNode *Tree::search(TreeNode* currentRoot, int key){
    if(currentRoot == nullptr) {
        return currentRoot;
    }
    else if (currentRoot->getValue() == key){
        return currentRoot;
    }
    else if (key < currentRoot->getValue()){
        return search(currentRoot->left, key);
    }
    else if (key > currentRoot->getValue()) {
        return search(currentRoot->right, key);
    }
    return nullptr;
}

inline int Tree::depth(TreeNode *currentRoot, TreeNode *node, int iterations)
{
    if(currentRoot == node)
        return iterations;
    if(node->getValue() < currentRoot->getValue()){
        return depth(currentRoot->left, node, iterations + 1);
    }
    if(node->getValue() > currentRoot->getValue()){
        return depth(currentRoot->right, node, iterations + 1);
    }
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

inline TreeNode *Tree::mostLeftSon(TreeNode *currentRoot)
{
    if(currentRoot == nullptr) 
        return currentRoot;

    if(currentRoot->left == nullptr){
        return currentRoot;
    }
    else {
        return mostLeftSon(currentRoot->left);
    }
}

inline TreeNode *Tree::mostRightSon(TreeNode *currentRoot)
{
    if(currentRoot == nullptr) 
        return currentRoot;

    if(currentRoot->right == nullptr){
        return currentRoot;
    }
    else {
        return mostRightSon(currentRoot->right);
    }
}

inline void Tree::preorder(TreeNode *currentRoot)
{
    if(currentRoot != nullptr) {
        cout << currentRoot->getValue() << " ";
        preorder(currentRoot->left);
        preorder(currentRoot->right);
    }
}

inline void Tree::inorder(TreeNode *currentRoot)
{
    if(currentRoot != nullptr) {
        inorder(currentRoot->left);
        cout << currentRoot->getValue() << " ";
        inorder(currentRoot->right);
    }
}

inline void Tree::postorden(TreeNode *currentRoot)
{
    if(currentRoot != nullptr) {
        postorden(currentRoot->left);
        postorden(currentRoot->right);
        cout << currentRoot->getValue() << " ";
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
    }
    else {
        cout << prefix;
        cout << (isLeft ? "├─" : "└─" );
        cout << "nil" << endl;
    }
}
