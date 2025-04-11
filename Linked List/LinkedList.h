#include <iostream>
struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        this->head = nullptr;
    }
    void insertFirst(Node *node)
    {

        node->next = head;
        head = node;
    }
    void insertLast(Node *node)
    {
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    bool find(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->val == val)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void remove(int val)
    {
        if (!find(val))
            return;
        Node *curr = head;
        Node *prev = head;
        while (curr->val != val)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->val << std::endl;
            temp = temp->next;
        }
    }
};