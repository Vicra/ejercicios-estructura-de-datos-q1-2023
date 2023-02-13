#include <iostream>
using namespace std;

#include "Node.h"

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
    void insertNodeAtStart(Node* newNode);
    void insertAfterNode(Node* referenceNode, Node* newNode);

    void deleteFirst();
    
    void printList();
    int getLength();
    void reverse();
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
    if(head->prev != nullptr && head->prev == this->tail){
        cout << "TAIL <";
    } else {
        cout << "NULL <";
    }
    Node* iterator = head;
    while(iterator != nullptr){
        cout << iterator->getValue();
        iterator = iterator->next;

        if (iterator == nullptr) cout << "> ";
        else cout << "<==>";
    }
    if(this->tail->next != nullptr && this->tail->next == this->head){
        cout << "> HEAD";
    } else {
        cout << "NULL\n";
    }

    cout << "Head: " << this->head->getValue() << " ";
    cout << "Tail: " << this->tail->getValue() << "\n\n";
}

int DoubleLinkedList::getLength()
{
    return this->length;
}

void DoubleLinkedList::reverse()
{
    this->tail = head;
    Node* tmp1 = this->head;
    Node* tmp2 = tmp1->next;
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

int main(int argc, char const *argv[])
{
    DoubleLinkedList * list = new DoubleLinkedList();
    list->insert(1, 0);
    list->insert(2, 0);
    list->insert(4, 2);

    list->reverse();
    list->printList();

    Node* nodeFive = new Node(5);
    list->insertNodeAtStart(nodeFive);
    list->insertAfterNode(nodeFive, new Node(6));
    
    list->printList();
    list->deleteFirst();
    list->printList();
    return 0;
}

void DoubleLinkedList::deleteFirst()
{
    Node* tmp = this->head;
    this->head = this->head->next;
    this->head->prev = this->tail;
    delete tmp;
}
