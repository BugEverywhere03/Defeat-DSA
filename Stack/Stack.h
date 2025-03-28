#include <vector>

class Stack
{
private:
    std::vector<int> stack;

public:
    Stack(std::vector<int> vecStack)
    {
        stack = vecStack;
    }
    void push(int value)
    {
        stack.push_back(value);
    }
    void pop()
    {
        stack.pop_back();
    }
    int top()
    {
        return stack[stack.size() - 1];
    }
    bool empty()
    {
        return stack.empty();
    }
    int size()
    {
        return stack.size();
    }
};

