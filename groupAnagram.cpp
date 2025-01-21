#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// O(n^3) Space: O(n)
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     unordered_set<string> set_string;
//     vector<vector<string>> result;
//     for (int i = 0; i < strs.size(); i++)
//     {
//         vector<string> vec;
//         if (set_string.find(strs[i]) != set_string.end())
//             continue;
//         int counts = 0;
//         for (int j = 0; j < strs[i].length(); j++)
//         {
//             char temp = strs[i][j];
//             counts += temp - 'a';
//         }
//         for (int k = 0; k < strs.size(); k++)
//         {
//             int currcount = 0;
//             for (int j = 0; j < strs[k].length(); j++)
//             {
//                 char temp = strs[k][j];
//                 currcount += temp - 'a';
//             }
//             if (currcount == counts)
//             {
//                 vec.push_back(strs[k]);
//                 set_string.insert(strs[k]);
//             }
//         }
//         result.push_back(vec);
//     }
//     return result;
// }
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> result;
    sort(strs.begin(), strs.end());
    vector<string> temp;
    temp.push_back(strs[0]);
    for (int i = 1; i < strs.size(); i++)
    {
        string conststring = temp[0];
        string currstring = strs[i];
        if (conststring.length() == currstring.length())
        {
            int curr_count = 0, next_count = 0;
            for (int j = 0; j < currstring.length(); j++)
            {
                curr_count = conststring[j] - 'a';
                next_count = currstring[j] - 'a';
            }
            if (curr_count == next_count)
                temp.push_back(currstring);
            else
            {
                result.push_back(temp);
                temp.clear();
                temp.push_back(currstring);
            }
        }
        else
        {
            result.push_back(temp);
            temp.clear();
            temp.push_back(currstring);
        }
    }
    result.push_back(temp);
    return result;
}

int main()
{
    vector<string> strs;
    int n;
    cout << "Enter N:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }
    for (string s : strs)
        cout << s << " ";
    cout << endl;
    vector<vector<string>> result = groupAnagrams(strs);
    for (vector<string> vec : result)
    {
        for (string s : vec)
            cout << s << " ";
        cout << endl;
    }

    for (string s : strs)
        cout << s << " ";
    cout << endl;
    return 0;
}