#include <iostream>
#include <string>
#include "NodeTree.h"

using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

class AVLTree
{
private:  
  NodeTree* newNode(int value);
  int getBalance(NodeTree *node);
  int height(NodeTree *node);
  int max(int a, int b);

  void showTrunks(Trunk *p)
  {
      if (p == nullptr) {
          return;
      }
  
      showTrunks(p->prev);
      cout << p->str;
  }

public:
  NodeTree* root;

  AVLTree(/* args */);
  ~AVLTree();

  NodeTree* insert(NodeTree* root, int value);
  NodeTree* deleteNode(NodeTree* root, int key);
  NodeTree* mostLeftSon(NodeTree* root);
  NodeTree* rightRotate(NodeTree *y);
  NodeTree* leftRotate(NodeTree *x);
  void inorder(NodeTree *currentRoot);
  void print(NodeTree* root);

  void printTree(NodeTree* root, Trunk *prev, bool isLeft)
  {
      if (root == nullptr) {
          return;
      }
  
      string prev_str = "    ";
      Trunk *trunk = new Trunk(prev, prev_str);
  
      printTree(root->right, trunk, true);
  
      if (!prev) {
          trunk->str = "———";
      }
      else if (isLeft)
      {
          trunk->str = ".———";
          prev_str = "   |";
      }
      else {
          trunk->str = "`———";
          prev->str = prev_str;
      }
  
      showTrunks(trunk);
      cout << " " << root->value << endl;
  
      if (prev) {
          prev->str = prev_str;
      }
      trunk->str = "   |";
  
      printTree(root->left, trunk, false);
  }
};

AVLTree::AVLTree()
{
}

AVLTree::~AVLTree()
{
}


void AVLTree::print(NodeTree *root)
{
    this->printTree(root, nullptr, false);
    cout << endl << endl;
}


void AVLTree::inorder(NodeTree *currentRoot)
{
    if(currentRoot != nullptr) {
        inorder(currentRoot->left);
        cout << currentRoot->value << " ";
        inorder(currentRoot->right);
    }
}

NodeTree* AVLTree::newNode(int value)
{
	NodeTree* node = new NodeTree();
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1;
	return(node);
}

int AVLTree::getBalance(NodeTree *node)
{
	if (node == nullptr)
		return 0;
	return height(node->left) - height(node->right);
}

int AVLTree::height(NodeTree *node)
{
	if (node == nullptr)
		return 0;
	return node->height;
}

int AVLTree::max(int a, int b)
{
	return (a > b)? a : b;
}

NodeTree* AVLTree::insert(NodeTree* node, int value)
{
  // Insert de BST
	if (node == nullptr)
		return(newNode(value));

	if (value < node->value)
		node->left = insert(node->left, value);
	else if (value > node->value)
		node->right = insert(node->right, value);
	else
		return node;

  // Actualizar la altura del nodo padre directo del nuevo nodo
	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = getBalance(node);

	// Caso1: Izquierdo Izquierdo
	if (balance > 1 && value < node->left->value)
		return rightRotate(node);

	// Caso2: Derecho Cerecho
	if (balance < -1 && value > node->right->value)
		return leftRotate(node);

  // Caso3: Izquierdo Derecho
	if (balance > 1 && value > node->left->value)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Caso5: Derecho Izquierdo
	if (balance < -1 && value < node->right->value)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

NodeTree* AVLTree::rightRotate(NodeTree *y)
{
	NodeTree *x = y->left;
	NodeTree *T2 = x->right;

	// Rotacion
	x->right = y;
	y->left = T2;

	// Actualizar las alturas
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// nueva raiz
	return x;
}

NodeTree* AVLTree::leftRotate(NodeTree *x)
{
	NodeTree *y = x->right;
	NodeTree *T2 = y->left;

	// Rotacion
	y->left = x;
	x->right = T2;

	// Actualizar las alturas
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// nueva raiz
	return y;
}

NodeTree* AVLTree::deleteNode(NodeTree* currentRoot, int valueToDelete)
{
    if (currentRoot == nullptr)
        return currentRoot;
 
    if ( valueToDelete < currentRoot->value )
        currentRoot->left = deleteNode(currentRoot->left, valueToDelete);
 
    else if( valueToDelete > currentRoot->value )
        currentRoot->right = deleteNode(currentRoot->right, valueToDelete);
 
    else
    {
        // Caso 1 y 2: sin hijos o un hijo
        if( (currentRoot->left == nullptr) ||
            (currentRoot->right == nullptr) )
        {
            NodeTree *subArbol = currentRoot->left ?
                         currentRoot->left :
                         currentRoot->right;

            // Caso 1: Sin hijos
            if (subArbol == nullptr)
            {
                subArbol = currentRoot;
                currentRoot = nullptr;
            }
            else // Caso 2: 1 Hijo
            // apunto al contenido del subarbol a conservar
            *currentRoot = *subArbol;
            free(subArbol);
        }
        else
        {
            // Caso 3: tengo 2 hijos
            NodeTree* succesor = mostLeftSon(currentRoot->right);
            currentRoot->value = succesor->value;
            currentRoot->right = deleteNode(currentRoot->right,
                                     succesor->value);
        }
    }
 
    // si no hay elementos no es necesario balancear
    if (currentRoot == NULL)
        return currentRoot;
 
    currentRoot->height = 1 + max(height(currentRoot->left),
                           height(currentRoot->right));
    int balance = getBalance(currentRoot);
 
    // Izquierdo Izquierdo 
    if (balance > 1 &&
        getBalance(currentRoot->left) >= 0)
        return rightRotate(currentRoot);
 
    // Izquierdo Derecho 
    if (balance > 1 &&
        getBalance(currentRoot->left) < 0)
    {
        currentRoot->left = leftRotate(currentRoot->left);
        return rightRotate(currentRoot);
    }
 
    // Derecho Derecho 
    if (balance < -1 &&
        getBalance(currentRoot->right) <= 0)
        return leftRotate(currentRoot);
 
    // Derecho Izquierdo 
    if (balance < -1 &&
        getBalance(currentRoot->right) > 0)
    {
        currentRoot->right = rightRotate(currentRoot->right);
        return leftRotate(currentRoot);
    }
 
    return currentRoot;
}


inline NodeTree *AVLTree::mostLeftSon(NodeTree *currentRoot)
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