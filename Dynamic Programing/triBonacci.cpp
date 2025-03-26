#include <iostream>
#include <unordered_map>
using namespace std;

int helpTriBonacci(int n, unordered_map<int, int> &memo)
{
    if (memo.find(n) == memo.end())
    {
        memo[n] = helpTriBonacci(n - 1, memo) + helpTriBonacci(n - 2, memo) + helpTriBonacci(n - 2, memo);
    }
    return memo[n];
}

int tribonacci(int n)
{
    unordered_map<int, int> memo;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    if (n <= 2)
        return memo[n];
    return helpTriBonacci(n, memo);
}

int main()
{
    cout << tribonacci(38);
    return 0;
}
