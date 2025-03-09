#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (denominator == 1)
    {
        return to_string(numerator);
    }
    double fraction = (float)numerator / denominator;
    string tempString = to_string(fraction);
    int dotIndex = 0;
    int zeroIndex = -1;
    for (int i = 0; i < tempString.length(); ++i)
    {
        if (tempString[i] == '.')
        {
            dotIndex = i;
            break;
        }
    }
    string subString = tempString.substr(dotIndex + 1);
    int i = subString.length() - 1;
    while (i >= 0)
    {
        if (subString[i] != '0')
        {
            zeroIndex = i;
            break;
        }
    }
    if (zeroIndex != subString.length() - 1)
        return tempString.substr(0, dotIndex) + subString.substr(0, zeroIndex);
    else
    {
        unordered_set<char> set;
        int left = 0, right = 0;
        while (right < subString.length())
        {
            if (set.find(subString[right]) != set.end())
            {
                int j = right;
                while (right < subString.length())
                {
                    if (set.find(subString[j]) != set.end())
                        right++;
                }
            }
            else
            {
            }
        }
    }
}

int main()
{
    fractionToDecimal(1, 4);
    return 0;
}