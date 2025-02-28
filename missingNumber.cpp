#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Using sort algorithms
// Time complexity O(nlogn) Space complexity O(1)
// int missingNumber(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         if (i != nums[i])
//             return i;
//     }
// }
// using hash table
// time complexity O(n) / Space complexity O(n)
// int missingNumber(vector<int> &nums)
// {
//     unordered_set<int> checkNum;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         checkNum.insert(nums[i]);
//     }
//     int target = 0;
//     for (int i = 0; i <= nums.size(); ++i)
//     {
//         if (checkNum.find(i) == checkNum.end())
//         {
//             target = i;
//             break;
//         }
//     }
//     return target;
// }
// using math
// time complexity O(n) Space complexity O(1)
int missingNumber(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
    }
    int fullSum = (nums.size() + 1) * (nums.size()) / 2;
    return fullSum - sum;
}
int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 6};
    cout << "Missing Number is " << missingNumber(nums);
    return 0;
}