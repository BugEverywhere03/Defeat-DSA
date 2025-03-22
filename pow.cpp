#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n == INT_MAX)
    {
        return ((x == 1) ? 1 : (x == -1) ? -1
                                         : 0);
    };
    if (n == INT_MIN)
        (x == 1 || x == -1) ? 1 : 0;
    if (n < 0)
    {
        n *= -1;
        x = 1 / x;
    }
    double result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= x;
    }
    return result;
}
double myPowRecusion(double x, int n)
{
    if (n == INT_MIN && (x == 1 || x == -1))
        return 1;
    else
        return 0;
    if (n == INT_MAX)
    {
        if (x == 1)
            return 1;
        else if (x == -1)
            return -1;
        else
            return 0;
    }
    if (n < 0)
    {
        x = 1 / x;
        n *= -1;
    }
    return (n % 2 == 0) ? x * x * myPowRecusion(x, n / 2) : x * myPow(x, n - 1);Zu
}

int main()
{
    int n = 10;
    double x = 2.0000;
    cout << myPow(x, n) << endl;
    return 0;
}