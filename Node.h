#ifndef NODE_H
#define NODE_H
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *createBSTPerfect(Node *root, int level, int &height)
{
    if (level > height)
    {
        return nullptr;
    }
    int val;
    cout << "Enter value= ";
    cin >> val;
    cout << endl;
    root = new Node(val);
    root->left = createBSTPerfect(root->left, level + 1, height);
    root->right = createBSTPerfect(root->right, level + 1, height);
    return root;
}

void travelTree(Node *root)
{
    if (root == NULL)
    {
        cout << nullptr << endl;
        return;
    }
    cout << root->val << endl;
    travelTree(root->left);
    travelTree(root->right);
}
// void travelRight(TreeNode*)
// {
// }
#endif