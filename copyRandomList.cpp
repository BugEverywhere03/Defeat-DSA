#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    };
};

Node *copyRandomList(Node *head)
{
    Node *curr = head;
    unordered_map<Node *, Node *> nodeMap;
    while (curr)
    {
        nodeMap[curr] = new Node(curr->val);
        curr = curr->next;
    }
    curr = head;
    while (curr)
    {
        Node *temp = nodeMap[curr];
        temp->next = nodeMap[curr->next];
        temp->random = nodeMap[curr->random];
        curr = curr->next;
    }
    return nodeMap[head];
}

void main()
{
}