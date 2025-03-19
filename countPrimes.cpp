#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// Solution Base
// Time complexity: O(sqrt(n) * n) | Space complexity: O(1)
// bool isPrime(int n)
// {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i <= sqrt(n); ++i)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }
// int countPrimes(int n)
// {
//     int countPrimes = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         if (isPrime(i))
//         {
//             ++countPrimes;
//         }
//     }
//     return countPrimes;
// }

//  Time complexity O(n*loglogn)
int countPrimes(int n)
{
    if (n <= 1)
        return 0;
    vector<bool> prime(n, true);
    for (int i = 2; i < sqrt(n); ++i)
    {
        if (prime[i])
        {
            int j = i * i;
            while (j <= n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; ++i)
    {
        if (prime[i])
            count++;
    }
    return count;
}
int main()
{
    cout << countPrimes(10) << endl;
    return 0;
}