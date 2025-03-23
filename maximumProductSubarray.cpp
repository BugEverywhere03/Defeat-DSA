#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums)
{
    vector<int> memoryLeft;
    vector<int> memoryRight;
    int currLeft = 1;
    int currRight = 1;
    int minLeft = 1;
    int minRight = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        int temp = currLeft;
        currLeft = max(max(nums[i] * currLeft, nums[i] * minLeft), nums[i]);
        minLeft = min(min(nums[i] * temp, nums[i] * minLeft), nums[i]);
        temp = currRight;
        currRight = max(max(nums[nums.size() - 1 - i] * currRight, nums[nums.size() - 1 - i] * minRight), nums[nums.size() - 1 - i]);
        minRight = min(min(nums[nums.size() - 1 - i] * temp, nums[nums.size() - 1 - i] * minRight), nums[nums.size() - 1 - i]);
        cout << currLeft << " " << minLeft << " " << currRight << " " << minRight << "\n";
        memoryLeft.push_back(currLeft);
        memoryRight.push_back(currRight);
    }
    int maxRight = INT_MIN;
    int maxLeft = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        maxRight = max(maxRight, memoryRight[i]);
        maxLeft = max(maxLeft, memoryLeft[i]);
    }
    return (maxRight > maxLeft ? maxRight : maxLeft);
}

int main()
{
    vector<int> nums = {-2, -3, -4, 0}; // 12\
    // -2, -2 0 0
    // 6, -3, 0, -4
    // 12, -24, 12, -3
    // 0, 0, 6, - 24;
    cout << maxProduct(nums); // Output = 6
    return 0;
}