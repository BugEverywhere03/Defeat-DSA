#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode
// {
//     string notation;
//     TreeNode *left;
//     TreeNode *right;
// };

// TreeNode *buildTree(vector<int> reversePolishNotation, int start, int end, int &curr, map<string, int> indexs)
// {
// }
int evalRPN(vector<string> &polishnotation)
{
    stack<int> numbers;
    for (int i = 0; i < polishnotation.size(); ++i)
    {
        if (polishnotation[i] == "*" || polishnotation[i] == "/" || polishnotation[i] == "+" || polishnotation[i] == "-")
        {
            int numOne = numbers.top();
            numbers.pop();
            int numberTwo = numbers.top();
            numbers.pop();
            if (polishnotation[i] == "*")
                numbers.push(numberTwo * numOne);
            if (polishnotation[i] == "+")
                numbers.push(numOne + numberTwo);
            if (polishnotation[i] == "-")
                numbers.push(numberTwo - numOne);
            if (polishnotation[i] == "/")
                numbers.push(numberTwo / numOne);
        }
        else
        {
            numbers.push(stoi(polishnotation[i]));
        }
    }
    return numbers.top();
}

int main()
{
    vector<string> polishnotation = {"2", "1",
                                     "+",
                                     "3", "*"};
    cout << evalRPN(polishnotation) << endl;
    return 0;
}