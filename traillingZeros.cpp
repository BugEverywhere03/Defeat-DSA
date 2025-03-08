#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// int traillingZeroes(int n)
// {
//     if (n == 0)
//         return 0;
//     int factorial = 1;
//     for (int i = 1; i <= n; ++i)
//     {
//         factorial *= i;
//     }
//     // string convertFactorial = to_string(factorial);
//     int countZeroes = 0;
//     // int length = convertFactorial.length();
//     // int left = 0;
//     // int right = 0;
//     // while (right < length)
//     // {
//     //     if (convertFactorial[right] == '0' && convertFactorial[left] == '0')
//     //     {
//     //         while (right < length && convertFactorial[right] == '0')
//     //         {
//     //             ++right;
//     //         }
//     //         countZeroes = max(countZeroes, right - left);
//     //         left = right;
//     //     }
//     //     else
//     //     {
//     //         if (convertFactorial[left] != '0')
//     //             left++;
//     //         right++;
//     //     }
//     // }
//     cout << factorial << endl;
//     int currCount = 0;
//     while (factorial != 0)
//     {
//         int temp = factorial % 10;
//         if (temp == 0)
//             ++currCount;
//         else
//         {
//             countZeroes = max(countZeroes, currCount);
//             currCount = 0;
//         }
//         factorial /= 10;
//     }
//     return countZeroes;
// }
// int traillingZeroes(int n)
// {
//     int count = 0;
//     while (n >= 5)
//     {
//         count += n / 5;
//         n /= 5;
//     }
//     return count;
// }
int traillingZeroes(int n)
{
    int count = 0;
    for (long long i = 5; n / i; i *= 5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    int n = 30;
    cout << traillingZeroes(n);
    return 0;
}
