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
void backtrackoptimize(vector<vector<string>> &result, vector<vector<bool>> &dp, vector<string> &par, int start, string s)
{
    if (start == s.length())
    {
        result.push_back(par);
        return;
    }

    for (int i = start; i < s.length(); i++)
    {
        if (dp[start][i])
        {
            par.push_back(s.substr(start, i - start + 1));
            backtrackoptimize(result, dp, par, i + 1, s);
            par.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> par;
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // Gán các chuỗi có độ dài 1 bằng True vì nó đối xứng
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    // Gán gía trị cho các chuổi có độ dài lớn hơn 2
    for (int length = 2; length <= n; ++length)
    {
        for (int i = 0; i <= n - length; ++i)
        {
            int j = i + length - 1;
            if (length == 2)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }
    // backtrack(result, s, par, 0);
    backtrackoptimize(result, dp, par, 0, s);
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