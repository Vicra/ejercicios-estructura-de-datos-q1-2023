#include <iostream>
using namespace std;

class Node
{
private:
    int value;
public:

    // properties
    Node* prev;
    Node* next;

    // constr and destr    
    Node(int);
    ~Node();

    // functions
    int getValue();
};

Node::Node(int newValue)
{
    this->value = newValue;
    this->prev = nullptr;
    this->next = nullptr;
}

Node::~Node()
{
}

int Node::getValue()
{
    return this->value;
}

class DoubleLinkedList
{
private:
    void insertAtStart(int newValue);
    void insertAtEnd(int newValue);
    int length;
public:
    Node* head;
    Node* tail;
    DoubleLinkedList();
    ~DoubleLinkedList();

    // functions/operations
    void insert(int newValue, int position);
    /*
        when pos = 0
            insertAtStart()
        when pos = n
            insertAtEnd()
        else
            insertBetween(Node)
    */

   void printList();
   int getLength();
};

DoubleLinkedList::DoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
}

void DoubleLinkedList::insert(int newValue, int position)
{
    if (position == 0) {
        insertAtStart(newValue);
    }
    else if (position == this->getLength()) {
        insertAtEnd(newValue);
    }
    this->length++;
}

void DoubleLinkedList::insertAtStart(int newValue)
{
    Node *newNode = new Node(newValue);

    // validar que la lista no este vacia
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        return;
    }
    else {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
}

void DoubleLinkedList::insertAtEnd(int newValue)
{
    Node *newNode = new Node(newValue);

    // validar que la lista no este vacia
    //  TODO: DRY should we put this in a separate fn?
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        return;
    }
    else {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

void DoubleLinkedList::printList()
{
    Node* iterator = head;
    while(iterator != nullptr){
        cout << iterator->getValue() << "<==>";
        iterator = iterator->next;
    }
    cout << "NULL\n";

    cout << "Head: " << this->head->getValue();
    cout << "Tail: " << this->tail->getValue() << "\n";
}

int DoubleLinkedList::getLength()
{
    return this->length;
}

int main(int argc, char const *argv[])
{
    DoubleLinkedList * list = new DoubleLinkedList();
    list->insert(1, 0);
    list->insert(2, 0);

    // 2 <==> 1 <==> NULL
    list->printList();

    list->insert(4, 2);
    // 2 <==> 1 <==> 4 <==> NULL
    list->printList();
    return 0;
}
