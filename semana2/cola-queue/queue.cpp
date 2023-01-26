#include <iostream>
using namespace std;


class Node
{
public:
    int value;
    Node* next;
    Node(int newValue);
    ~Node();

    int getValue();
};

Node::Node(int newValue)
{
    this->value = newValue;
    this->next = nullptr;
}

Node::~Node()
{
}

int Node::getValue()
{
    return this->value;
}

class Queue
{
private:
    Node* tail;
public:
    // [A1, A2, A3, A4]
    Queue(int initialValues[]);
    Queue();
    ~Queue();

    // insert Node
    void enqueue(int newValue);
    void print();

    // TODO: 
    // dequeue () || shift()
    // peek()
    // apuntador a HEAD
};

Queue::Queue(int initialValues[])
{
    this->tail = nullptr;
    for (int i = 0; i < 4 ; i++)
    {
        // cout << initialValues[i];
        this->enqueue(initialValues[i]);
    }

    // for (int i : initialValues){
    //     this->enqueue(initialValues[i]);
    // }
    
}

Queue::Queue()
{
    tail = nullptr;
}

Queue::~Queue()
{
}

void Queue::enqueue(int newValue)
{
    Node* newNode = new Node(newValue);
    // caso base : no hay elementos en la cola
    if (this->tail == nullptr) {
        this->tail = newNode;
        return;
    }

    // caso 2 : si hay elementos en la lista
    newNode->next = this->tail;
    this->tail = newNode;
}

void Queue::print()
{
    Node * iteratorNode = this->tail;
    while (iteratorNode != nullptr) {
        cout << iteratorNode->getValue() << " -> ";
        iteratorNode = iteratorNode->next;
    }
    cout << "null\n";
}


int main(int argc, char const *argv[])
{
    int initialValues [4] = {1, 2, 3, 4};
    Queue *queue = new Queue(initialValues);
    queue->print();
    return 0;
}
