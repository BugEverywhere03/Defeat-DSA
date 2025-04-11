#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    list.insertFirst(new Node(4));
    list.insertFirst(new Node(3));
    list.insertFirst(new Node(2));
    list.insertFirst(new Node(1));
    list.printList();
    list.remove(2);
    list.printList();
    return 0;
}
