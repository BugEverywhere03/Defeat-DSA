#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int uniquePath(int m, int n)
{
    int maxValue = min(m - 1, n - 1);
    int result = 1;
    for (int i = 1; i <= maxValue; i++)
    {
        cout << m + n - 2 - i << endl;
        result *= (m + n - 2 - maxValue + i);
        result /= i;
    }
    return result;
}

int main()
{
    int result = uniquePath(3, 7);
    cout << result << endl;
    return 0;
}