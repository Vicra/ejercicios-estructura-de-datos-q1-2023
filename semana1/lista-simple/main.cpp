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
    bool deleteNode(int valueToDelete);

    // TODO: hacer estas funciones para practicar
    // includes(value) contains(value) = buscar
    // deleteAt(index)
    // reverseList()
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
    cout << "null\n";
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

/*
    retorna true si borra exitosamente
    retorna false si no encuentra el elemento a borrar
*/
bool SimpleList::deleteNode(int valueToDelete) 
{
    bool isDeleteComplete = false;
    // caso base, si es el primer nodo de la lista
    if(this->first->value == valueToDelete) {
        this->first = this->first->next;
        isDeleteComplete = true;
    }

    // case 2: borrar cualquier elemento de enmedio de la lista
    Node *iteratorNode = this->first;
    while (iteratorNode->next != nullptr) {
        if(iteratorNode->next->value == valueToDelete) {
            // estoy borrando
            iteratorNode->next = iteratorNode->next->next;
            isDeleteComplete = true;
            break;
        }
        iteratorNode = iteratorNode->next;
    }

    // TODO: check code
    // caso 3: que pasa si se borra el ultimo?
    if (isDeleteComplete) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return isDeleteComplete;
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

    list->deleteNode(12);
    list->printList();
    // 9 -> 3 -> 1 -> null

    list->insertNode(13);
    // 9 -> 3 -> 1 -> 13 -> null

    // borrar uno de enmedio
    list->deleteNode(3);
    list->printList();
    // 9 -> 1 -> 13 -> null

    list->deleteNode(5);

    // end of code
    delete list;
    return 0;
}
