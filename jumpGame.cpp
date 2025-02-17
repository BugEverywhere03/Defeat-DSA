#include <iostream>
#include <vector>
using namespace std;

bool jumpGame(vector<int> nums)
{
    int target = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; --i)
    {
        if (i + nums[i] >= target)
        {
            target = i;
        }
    }
    return target == 0 ? true : false;
}
int jumpGameTwo(vector<int> nums)
{
    int i = nums.size() - 1;
    while (i > 0)
    {
        int j = 0;
        while (j < i)
        {
            if (nums[j] + j >= i)
                break;
            j++;
        }
        if (j == i)
            return false;
        else
            i--;
    }
    return i == 0 ? true : false;
}

int main()
{
    vector<int> nums = {4, 0, 0, 2, 0, 4};
    cout << jumpGame(nums) << endl;
    cout << jumpGameTwo(nums) << endl;
    return 0;
}