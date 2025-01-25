#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int redCount = 0;
    int whiteCount = 0;
    int greenCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            ++redCount;
        if (nums[i] == 1)
            ++whiteCount;
        if (nums[i] == 2)
            ++greenCount;
    }
    cout << "RedCount " << redCount << endl;
    cout << "WhiteCount " << whiteCount << endl;
    cout << "GreenCount " << greenCount << endl;
    int j = 0;
    while (j < nums.size())
    {
        if (j < redCount)
        {
            cout << "1" << endl;
            nums[j] = 0;
        }
        if (j >= redCount && j < whiteCount + redCount)
        {
            cout << "2" << endl;
            nums[j] = 1;
        }
        if (j >= whiteCount + redCount)
        {
            cout << "3" << endl;
            nums[j] = 2;
        }
        j++;
    }
}
int main()
{
    vector<int> nums = {0, 1, 2, 1, 2, 0};
    sortColors(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}