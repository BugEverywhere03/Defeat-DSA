#include <iostream>
#include <string>
using namespace std;

int traillingZeroes(int n)
{
    if (n == 0)
        return 0;
    int factorial = 1;
    for (int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }
    cout << factorial << endl;
    string convertFactorial = to_string(factorial);
    int countZeroes = 0;
    int length = convertFactorial.length();
    int left = 0;
    int right = 0;
    while (right < length)
    {
        if (convertFactorial[right] == '0' && convertFactorial[left] == '0')
        {
            while (right < length && convertFactorial[right] == '0')
            {
                ++right;
            }
            countZeroes = max(countZeroes, right - left);
            left = right;
        }
        else
        {
            if (convertFactorial[left] != '0')
                left++;
            right++;
        }
    }
    return countZeroes;
}

int main()
{
    int n = 7;
    cout << traillingZeroes(n);
    return 0;
}
