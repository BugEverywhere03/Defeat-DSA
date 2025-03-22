#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *createNode(int val)
{
    ListNode *newNode = new ListNode();
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}
void insertNodeToList(ListNode *&head, ListNode *newNode)
{
    newNode->next = head;
    head = newNode;
}

void createList(ListNode *&head)
{
    int n;
    cout << "Enter N = " << endl;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int val;
        cout << "Enter Value Node = " << endl;
        cin >> val;
        ListNode *newNode = createNode(val);
        insertNodeToList(head, newNode);
    }
}