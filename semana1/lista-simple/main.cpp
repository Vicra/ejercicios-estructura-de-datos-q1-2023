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

    // funciones
    bool isEmpty();
};

SimpleList::SimpleList()
{
}

SimpleList::~SimpleList()
{
}
