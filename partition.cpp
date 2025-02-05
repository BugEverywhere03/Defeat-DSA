#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool isPalindrome(string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
void backtrack(vector<vector<string>> &result, string s, vector<string> &par, int start)
{
    if (start == s.length())
    {
        result.push_back(par);
        return;
    }
    for (int i = start; i < s.length(); ++i)
    {
        if (isPalindrome(s, start, i))
        {
            par.push_back(s.substr(start, i - start + 1));
            backtrack(result, s, par, i + 1);
            par.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> par;
    backtrack(result, s, par, 0);
    return result;
}

int main()
{
    string s = "aab";
    vector<vector<string>> pars = partition(s);
    for (auto v : pars)
    {
        for (auto str : v)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}