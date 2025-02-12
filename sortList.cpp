#include <iostream>
#include <algorithm>
#include <vector>
#include "ListNode.cpp"

ListNode *sortList(ListNode *&head)
{
    vector<int> arrayNode;
    ListNode *curr = head;
    while (curr)
    {
        arrayNode.push_back(curr->val);
        curr = curr->next;
    }
    sort(arrayNode.begin(), arrayNode.end());
    int i = 0;
    curr = head;
    while (curr)
    {
        curr->val = arrayNode[i];
        curr = curr->next;
        i++;
    }
}

int main()
{
    ListNode *head = nullptr;
    createList(head);
    head = sortList(head);
    while (head)
    {
        cout << head->val << endl;
        head = head->next;

    }
    return 0;
}