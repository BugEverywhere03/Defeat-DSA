#include <iostream>
#include <stack>
#include "Node.h"
#include <queue>
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
    level = level - 1;
    while (!leftBranch.empty())
    {
        Node *prev = NULL;
        Node *curr = NULL;
        Node *endLeft = NULL;
        int countLeft = 1;
        while (countLeft <= level)
        {
            if (countLeft % 2 == 0)
            {
                prev = leftBranch.top();
                cout << "prev value" << prev->val << endl;
            }
            else
            {
                curr = leftBranch.top();
                cout << "curr value " << curr->val << endl;
            }
            if (prev)
                prev->next = curr;
            leftBranch.pop();
            if (countLeft == 1)
                endLeft = curr;
            ++countLeft;
        }
        int countRight = countLeft;
        Node *endRight = NULL;
        while (countRight <= 2 * level)
        {
            cout << "index " << countRight << endl;
            if (countRight % 2 == 0)
            {
                prev = rightBranch.top();
                cout << "prev value " << prev->val << endl;
            }
            else
            {
                curr = rightBranch.top();
                cout << "curr value " << curr->val << endl;
            }
            rightBranch.pop();
            if (prev)
                prev->next = curr;
            if (countRight == level + 1)
            {
                endRight = curr;
            }
            ++countRight;
        }
        if (endLeft)
            endLeft->next = prev;
        if (endRight)
            endRight->next = NULL;
    }
    return root;
}
Node *connectByBFS(Node *root)
{
    if (root == NULL)
        return NULL;
    queue<Node *> queueNode;
    queueNode.push(root);
    while (!queueNode.empty())
    {
        int size = queueNode.size();
        Node *prev = NULL;
        Node *curr = queueNode.front();
        queueNode.pop();
        if (prev)
            prev->next = curr;
        prev = curr;
        if (curr->left)
            queueNode.push(curr->left);
        if (curr->right)
            queueNode.push(curr->right);
        if (prev)
            prev->next = NULL;
    }
    return NULL;
}
int main()
{
    Node *root = new Node(1);
    int height = 1;
    root->left = createBSTPerfect(root->left, 1, height);
    root->right = createBSTPerfect(root->right, 1, height);
    travelTree(root);
    connect(root);
    travelTree(root);
    return 0;
}
