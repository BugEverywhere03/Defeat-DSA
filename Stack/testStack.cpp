#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

int main()
{
    std::vector<int> vecStack = {1, 2, 7, 5, 8};
    Stack stack(vecStack);
    cout << "Size " << stack.size() << "\n";
    cout << "Empty " << stack.empty() << "\n";
    cout << "Push 0\t";
    stack.push(0);
    cout << "\n";
    cout << "Pop\t";
    stack.pop(); 
    cout << "\n";
    cout << "Top " << stack.top(); // 8
    return 0;
}