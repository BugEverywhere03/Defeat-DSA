#include <iostream>
#include <vector>
using namespace std;

// Bad Solution
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size();
    int j = 2;
    for (int i = 2; i < nums.size(); ++i)
    {
        if (nums[i] != nums[j - 2])
        {
            nums[j] = nums[i];
            ++j;
        }
    }
    return j;
}

int main()
{
    vector<int> nums = {0, 0, 0, 1, 1, 1, 2, 2, 3};
    removeDuplicates(nums);
    for (int number : nums)
        cout << number << " "; // 1
    return 0;
}