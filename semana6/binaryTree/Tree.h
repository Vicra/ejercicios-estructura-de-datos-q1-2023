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

    TreeNode* insert(TreeNode *root, TreeNode* newNode);
    TreeNode* search(TreeNode* root, int key);
    TreeNode* deleteNode(TreeNode* root, int key);

    TreeNode* mostLeftSon(TreeNode* root);
    TreeNode* mostRightSon(TreeNode* root);

    // print algorithms
    void preorder(TreeNode* root);
    void inorder(TreeNode* root);
    void postorden(TreeNode* root);
    int depth(TreeNode* root, TreeNode* node, int interations);

    void print(string prefix, TreeNode* root, bool isLeft);
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

inline TreeNode *Tree::deleteNode(TreeNode *currentRoot, int key)
{
    if(currentRoot == nullptr)
        return currentRoot;
    
    // continue iterando || continue la recursion
    if(key < currentRoot->getValue())
        currentRoot->left = deleteNode(currentRoot->left, key);
    else if(key > currentRoot->getValue())
        currentRoot->right = deleteNode(currentRoot->right, key);
    else {
        // ya estoy en el nodo que quiero borrar
        
        // CASO 1: no tengo hijos
        if (currentRoot->left == nullptr && currentRoot->right == nullptr){
            free(currentRoot);
            return nullptr;
        }

        // CASO 2 (A): tengo 1 hijo derecho solamente
        else if (currentRoot->left == nullptr && currentRoot->right != nullptr) {
            TreeNode * temp = currentRoot->right;
            free(currentRoot);
            return temp;
        }

        // CASO 2 (B): tengo 1 hijo izquierdo solamente
        else if (currentRoot->right == nullptr && currentRoot->left != nullptr) {
            TreeNode * temp = currentRoot->left;
            free(currentRoot);
            return temp;
        }

        // CASO 3: tengo 2 hijos
        else { 
            TreeNode* succesor = mostLeftSon(currentRoot->right);
            currentRoot->setValue(succesor->getValue());
            currentRoot->right = deleteNode(currentRoot->right, succesor->getValue());
        }
    }
    return currentRoot;
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
    return 0;
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
