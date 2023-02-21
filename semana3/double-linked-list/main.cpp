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

    void printList();
    int getLength();
    void reverse();

    // TODO: delete first, delete last
    void insertNodeAtStart(Node* newNode);
    void insertAfterNode(Node* referenceNode, Node* newNode);

    void deleteNode(Node* nodeToDelete);
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
    if (this->head == nullptr || 
        (this->head == this->tail)) {
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
    if(iterator != nullptr) cout << "NULL<-";
    while(iterator != nullptr){
        cout << iterator->getValue();
        iterator = iterator->next;

        if(iterator != nullptr)
            cout << "<==>";
    }
    cout << "->NULL\n";

    if(this->head != nullptr)
        cout << "Head: " << this->head->getValue() << " ";
    else 
        cout << "Head: " << "nullptr" << endl;

    if(this->tail != nullptr)
        cout << "Tail: " << this->tail->getValue() << "\n\n";
    else
        cout << "Tail: " << "nullptr" << endl;
}

int DoubleLinkedList::getLength()
{
    return this->length;
}

void DoubleLinkedList::reverse()
{
    // asignar el tail
    this->tail = head;

    // definir los iteradores/temporales
    Node* tmp1 = this->head;
    Node* tmp2 = tmp1->next;

    // primer iteracion
    tmp1->next = nullptr;
    tmp1->prev = tmp2;

    while (tmp2 != nullptr) {
        tmp2->prev = tmp2->next;
        tmp2->next = tmp1;

        tmp1 = tmp2;
        tmp2 = tmp2->prev;
    }

    this->head = tmp1;
}

void DoubleLinkedList::insertNodeAtStart(Node *newNode)
{
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

void DoubleLinkedList::insertAfterNode(Node *referenceNode, Node *newNode)
{
    newNode->next = referenceNode->next;
    newNode->prev = referenceNode;

    referenceNode->next = newNode;
}

void DoubleLinkedList::deleteNode(Node *nodeToDelete)
{
    Node* temp = nodeToDelete;
    if(nodeToDelete == this->head){
        this->head = this->head->next;
        if(this->head != nullptr)
            this->head->prev = nullptr;

        // if head is also tail
        if(nodeToDelete == this->tail){
            this->tail = this->tail->prev;
            if(this->tail != nullptr)
                this->tail->next = nullptr;
        }
    }
    else if(nodeToDelete == this->tail){
        this->tail = this->tail->prev;
        if(this->tail != nullptr)
            this->tail->next = nullptr;
    }
    else {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    delete temp;
}

int main(int argc, char const *argv[])
{
    DoubleLinkedList * list = new DoubleLinkedList();
    list->insert(1, 0);
    list->insert(2, 0);

    // 2 <==> 1 <==> NULL
    list->printList();

    // list->insert(4, 2);
    // 2 <==> 1 <==> 4 <==> NULL
    // list->printList();

    list->reverse();
    list->printList();

    // first instance the node
    cout << "\nadding 5" << "\n";
    Node* nodeFive = new Node(5);
    list->insertNodeAtStart(nodeFive);
    list->insertNodeAtStart(new Node(7));
    list->insertAfterNode(nodeFive, new Node(6));
    list->printList();

    cout << "Deleting head" << endl;
    list->deleteNode(list->head);
    list->printList();

    cout << "Deleting tail" << endl;
    list->deleteNode(list->tail);
    list->printList();

    cout << "Deleting in middle" << endl;
    list->deleteNode(list->head->next);
    list->printList();

    list->deleteNode(list->head);
    list->printList();

    cout << "Deleting head and tail" << endl;
    list->deleteNode(list->head);
    list->printList();
    delete list;
    return 0;
}
