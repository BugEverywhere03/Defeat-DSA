#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Using max element in vector
// Time Complexity O(n) Space complexity O(1)
// int indexOfPeakElement(vector<int> &nums)
// {
//     int maxElement = INT_MIN;
//     int index = -1;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         if (nums[i] > maxElement)
//         {
//             maxElement = nums[i];
//             index = i;
//         }
//     }
//     return index;
// }
// using map
// Time complexity O(n) Space complexity(n)
// int indexOfPeakElement(vector<int> &nums)
// {
//     unordered_map<int, bool> check;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         if (i == 0)
//         {
//             if (nums[i] > nums[i + 1])
//                 check[i] = true;
//             else
//                 check[i] = false;
//             continue;
//         }
//         if (i == nums.size() - 1)
//         {
//             if (nums[i] > nums[i - 1])
//                 check[i] = true;
//             else
//                 check[i] = false;
//             continue;
//         }
//         if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//             check[i] = true;
//         else
//             check[i] = false;
//     }
//     for (auto iter : check)
//     {
//         cout << iter.first << " " << iter.second << "\n";
//     }
//     for (auto iter : check)
//     {
//         if (iter.second == true)
//             return iter.first;
//     }
//     return 0;
// }
// using binary search
// Time complexity O(logN) Space(1)
int indexOfPeakElement(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (mid != 0 && mid != nums.size() - 1)
        {
            if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
            {
                return mid;
            }
            else
            {
                if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid])
                {
                    if (nums[mid - 1] > nums[mid + 1])
                        right = mid;
                    else
                        left = mid;
                }
                else
                {
                    if (nums[mid] < nums[mid - 1])
                        right = mid;
                    if (nums[mid] < nums[mid + 1])
                        left = mid;
                }
            }
        }
        else
        {
            if (mid == 0)
            {
                if (nums[mid] > nums[mid + 1])
                    return mid;
                else
                {
                    left = left + 1;
                }
            }
            if (mid == nums.size() - 1)
            {
                if (nums[mid] > nums[mid - 1])
                    return mid;
                else
                {
                    right = right + 1;
                }
            }
        }
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << indexOfPeakElement(nums);
    return 0;
}