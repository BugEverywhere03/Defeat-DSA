#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums)
{
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < nums.size(); i += 2)
    {
        sumOdd += nums[i];
    }
    for (int i = 1; i < nums.size(); i += 2)
    {
        sumEven += nums[i];
    }
    return max(sumOdd, sumEven);
}

int main()
{
    vector<int> nums = {1, 2, 6, 4};
    cout << rob(nums);
    return 0;
}