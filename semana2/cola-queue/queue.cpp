#include <iostream>
using namespace std;
#include <string>

class Node
{
public:
    string value;
    Node* next;
    Node(int newValue);
    ~Node();
    string getValue();
};

Node::Node(int newValue)
{
    this->value = "A" + to_string(newValue);
    this->next = nullptr;
}

Node::~Node()
{
}

string Node::getValue()
{
    return this->value;
}

class Queue
{
private:
    Node* tail;
    int size;
    void incrementSize();
    void decrementSize();
    Node* head; // O(1) pero tmb se puede hacer con O(n)

public:
    // [A1, A2, A3, A4]
    Queue(int initialValues[]);
    ~Queue();

    // insert Node
    void enqueue(int newValue);
    void print();
    string dequeue();

    // handle size
    int getSize();

    // devuelve el valor del HEAD o el ultimo elemento
    string peek();

    // TODO: 
    // dequeue () || shift()
    // peek()
    // apuntador a HEAD
    /*
        1. inicialmente el head y tail son el mismo (n=0, n=1)
        2. cada vez que se haga delete(dequeue) debe de actulizar el head
        3. la fn peek no debe recorrer la lista O(1)
    */

};

Queue::Queue(int initialValues[])
{
    this->size = 0;
    this->tail = nullptr;
    this->head = nullptr;
    for (int i = 0; i < 4 ; i++)
    {
        this->enqueue(initialValues[i]);
    }
}

Queue::~Queue()
{
}

void Queue::enqueue(int newValue)
{
    this->incrementSize();
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

string Queue::dequeue()
{
    if(this->getSize() == 0) {
        return "";
    }
    else if (this->getSize() == 1) {
        string valueToReturn = this->tail->getValue();
        this->tail = nullptr;
        this->head = nullptr;
        this->decrementSize();
        return valueToReturn;
    }
    
    Node *iteratorNode = this->tail;
    string valueToReturn = "";
    while (iteratorNode->next != nullptr){
        // avanzar el apuntador
        if(iteratorNode->next->next == nullptr) {
            // estoy en el penultimo
            valueToReturn = iteratorNode->next->getValue();
            iteratorNode->next = iteratorNode->next->next;
            // iteratorNode->next = nullptr;
            // linea 111 y 112 son lo mismo

            this->head = iteratorNode;
            break;
        }
        iteratorNode = iteratorNode->next;
    }
    return valueToReturn;
    // this->decrementSize();
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

/*
    ++ en enqueue
    -- en dequeue
*/
int Queue::getSize()
{
    return this->size;
}

string Queue::peek()
{
    return this->head->getValue();
}

void Queue::incrementSize()
{
    this->size = this->size + 1;
}

void Queue::decrementSize()
{
    this->size = this->size - 1;
}

int main(int argc, char const *argv[])
{
    int initialValues [4] = {1, 2, 3, 4};
    Queue *queue = new Queue(initialValues);

    // int initialValues [1] = {3};
    // Queue *queue = new Queue(initialValues);
    queue->print();
    // A3 -> null

    cout << "dequeue: " << queue->dequeue() << "\n";
    cout << "peek: " << queue->peek() << "\n";
    queue->print();

    // 2
    cout << "dequeue: " << queue->dequeue() << "\n";
    cout << "peek: " << queue->peek() << "\n";

    // 3
    cout << "dequeue: " << queue->dequeue() << "\n";
    cout << "peek: " << queue->peek() << "\n";

    queue->print();
    // null
    return 0;
}
