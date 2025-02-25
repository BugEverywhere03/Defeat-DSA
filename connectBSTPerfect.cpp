#include <iostream>
#include <Node.h>
#include <stack>
using namespace std;

void DFS(Node *root, stack<Node *> &branch, int &level)
{
    if (root == NULL)
        return;
    branch.push(root);
    level++;
    DFS(root->left, branch, level);
    DFS(root->right, branch, level);
}
Node *connect(Node *root)
{
    if (root == NULL)
        return NULL;
    root->next = NULL;
    stack<Node *> leftBranch;
    stack<Node *> rightBranch;
    int level = 0;
    DFS(root->left, leftBranch, level);
    DFS(root->right, rightBranch, level);
    int leftSize = leftBranch.size();
    int rightSize = rightBranch.size();
    level = level / 4;
    while (!leftBranch.empty())
    {
        Node *prev = NULL;
        Node *curr = NULL;
        int countLeft = 0;
        while (countLeft < level)
        {
            curr = leftBranch.top();
            leftBranch.pop();
            if (prev != NULL)
                prev->next = curr;
            prev = curr;
            countLeft += 1;
        }
        int countRight = countLeft;
        while (countRight < 2 * level)
        {
            curr = rightBranch.top();
            prev->next = curr;
            if (countRight == 2 * level - 1)
                curr->next = NULL;
            prev = curr;
            ++countRight;
        }
    }
    return root;
}
