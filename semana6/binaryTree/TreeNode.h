class TreeNode
{
private:
    int value;
public:
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value);
    ~TreeNode();

    int getValue();
    int setValue(int newValue);
};

TreeNode::TreeNode(int value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

TreeNode::~TreeNode()
{
}

inline int TreeNode::getValue()
{
    return this->value;
}

inline int TreeNode::setValue(int newValue)
{
    return this->value = newValue;
}
