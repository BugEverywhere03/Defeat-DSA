#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<vector<int>> &result, vector<int> &nums, int start, vector<int> &set)
{
    result.push_back(set);
    if (start == nums.size())
    {
        return;
    }
    for (int i = start; i < nums.size(); ++i)
    {
        set.push_back(nums[i]);
        backtracking(result, nums, i + 1, set);
        set.pop_back();
    }
}
vector<vector<int>> subSets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> set;
    backtracking(result, nums, 0, set);
    return result;
}

int main()
{
    vector<vector<int>> result;
    vector<int> nums = {1, 2, 3, 4};
    result = subSets(nums);
    for (auto v : result)
    {
        for (int num : v)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}