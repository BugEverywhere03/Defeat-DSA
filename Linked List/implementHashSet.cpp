#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class MyHashSet
{
private:
    Node *head;

public:
    MyHashSet()
    {
        this->head = NULL;
    }
    void add(int key)
    {
        Node *temp = this->head;
        if (temp == NULL)
        {
            head = new Node(key);
            return;
        }
        Node *prev = NULL;
        while (temp)
        {
            if (temp->val == key)
                return;
            prev = temp;
            temp = temp->next;
        }
        prev->next = new Node(key);
    }

    void remove(int key)
    {
            Node *curr = this->head;
            if (curr == NULL)
                return;
            Node *prev = curr;
            while (curr && curr->val != key){
                prev = curr;
                curr = curr->next;
            }
            if (curr == head){
                head = curr->next;
            }
            if (curr)
                prev->next = curr->next;
    }

    bool contains(int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
void test(vector<string> &actions, vector<int> &values)
{
    MyHashSet myHashSet;
    map<string, int> lib = {{"MyHashSet", 1}, {"add", 2}, {"remove", 3}, {"contains", 4}};
    for (int i = 0; i < actions.size(); ++i)
    {
        int action = lib[actions[i]];
        switch (action)
        {
        case 1:
            myHashSet = MyHashSet();
            myHashSet.print();
            break;
        case 2:
            cout << "Add " << values[i] << endl;
            myHashSet.add(values[i]);
            myHashSet.print();
            break;
        case 3:
            cout << "Remove " << values[i] << endl;
            myHashSet.remove(values[i]);
            myHashSet.print();
            break;
        case 4:

            cout << "My hashset contain " << values[i] << endl;
            cout << myHashSet.contains(values[i]) << endl;
            myHashSet.print();
            break;
        default:
            break;
        }
    }
}
int main()
{
    vector<string> actions = {"MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"};
    vector<int> values = {0, 1, 2, 1, 3, 2, 2, 2, 2};
    test(actions, values);
    return 0;
}