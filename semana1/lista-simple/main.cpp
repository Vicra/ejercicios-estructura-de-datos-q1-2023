#include <iostream>
using namespace std;

class Node
{
public:
    // constructor
    Node(int newValue);
    ~Node();

    // properties
    int value;
    Node *next;
};

// esto se ejecuta cuando hago = new Node()
Node::Node(int newValue)
{
    this->value = newValue;
    this->next = nullptr;
}

// *********

class SimpleList
{
private:
    Node *first;
public:
    SimpleList();
    ~SimpleList();

    // funciones o operaciones
    // bool isEmpty();
    void insertNode(int newValue);
    void printList();
};

SimpleList::SimpleList()
{
    this->first = nullptr;
}

SimpleList::~SimpleList()
{
}
// 3 -> 6 -> null
void SimpleList::printList()
{
    Node * iteratorNode = this->first;
    while (iteratorNode != nullptr) {
        cout << iteratorNode->value << " -> ";
        iteratorNode = iteratorNode->next;
    }
    cout << "null";
}

void SimpleList::insertNode(int newValue)
{
    Node *newNode = new Node(newValue);

    // primer caso, lista esta vacia
    if (this->first == nullptr) {
        this->first = newNode;
        return;
    } else {
        // TODO: agregar al final de la lista
        // cuando la lista contiene elementos
        // ...

        Node *iteratorNode = this->first;

        // llegar hasta el ultimo elemento
        while (iteratorNode->next != nullptr) {
            // continue iterando
            iteratorNode = iteratorNode->next;
        }
        iteratorNode->next = newNode;
    }
}

int main(int argc, char const *argv[])
{
    SimpleList *list = new SimpleList();

    // here goes my code
    list->insertNode(12);
    list->insertNode(9);
    list->insertNode(3);
    list->insertNode(1);
    list->printList();

    // 12 -> 9 -> 3 -> 1 -> null
    // end of code
    delete list;
    return 0;
}
