class Node
{
private:
    int value;
public:
    Node* prev;
    Node* next;
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
