class NodeTree
{
  private:

	public:
    int value;
    int height;
    NodeTree *left;
    NodeTree *right;

    NodeTree(int value);
    NodeTree();
    ~NodeTree();
};

NodeTree::NodeTree(int value)
{
  this->value = value;
}

NodeTree::NodeTree()
{
}

NodeTree::~NodeTree()
{
}