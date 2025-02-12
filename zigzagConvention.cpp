#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string result = "";
    for (int i = 0; i < numRows; ++i)
    {
        int step = 2 * (numRows - 1);
        for (int j = i; j < s.length(); j += step)
        {
            result += s[j];
            int increment = 2 * (numRows - 1) - 2 * j;
            if (i != 0 && i != numRows - 1 && i + increment < s.length())
            {
                result += s[i + increment];
            }
        }
    }
    return result;
}

string convertV2(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int idxRow = 0;
    int step = -1;
    vector<string> tempVec(numRows, "");
    for (int i = 0; i < s.length(); ++i)
    {
        tempVec[idxRow] += s[i];
        if (i == 0)
            step = -1;
        if (i == numRows - 1)
            step = 1;
        idxRow += step;
    }
    string result = "";
    for (int i = 0; i < s.length(); ++i)
    {
        result += tempVec[i];
    }
    return result;
}

int main()
{
    string s = "PAYPALISHIRING";
    cout << convert(s, 3) << endl;
    cout << convert(s, 4) << endl;
    return 0;
}