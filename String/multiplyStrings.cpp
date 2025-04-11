#include <string>
#include <iostream>
using namespace std;

string multipli(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";
    string result = "";
    int temp = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || temp > 0)
    {
        int currResult = 1;
        if (i >= 0)
            currResult *= num1[i] - '0';
        if (j >= 0)
            currResult *= num2[j] - '0';
        if (i < 0 && j < 0)
            currResult = temp;
        else
            currResult += temp;
        cout << currResult << endl;
        temp = currResult / 10;
        result = to_string(currResult%10) + result;
        --i;
        --j;
    }
    return result;
}

int main()
{
    string num1 = "123";
    string num2 = "456";
    cout << multipli(num1, num2);
    return 0;
}