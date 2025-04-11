#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
    Heap heap;
    heap.push(5);
    heap.push(3);
    heap.push(9);
    std::cout << heap.top();
    return 0;
}