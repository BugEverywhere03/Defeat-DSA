#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Using quick sort algorithm
int longestConsequence(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int longestLength = 1;
    int currLength = 1;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] + 1 == nums[i + 1])
        {
            currLength++;
        }
        else
        {
            if (nums[i] == nums[i + 1])
            {
                continue;
            }
            longestLength = max(longestLength, currLength);
            currLength = 1;
        }
        longestLength = max(longestLength, currLength);
    }
    return longestLength;
}
// Using Map
int longestConsequenceTwo(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int longestLength = 0;
    unordered_set<int> sequence;
    for (int i = 0; i < nums.size(); ++i)
    {
        sequence.insert(i);
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (sequence.count(nums[i] - 1) == 0)
        {
            int j = 0;
            int count = 1;
            while (sequence.find(nums[i] + j) != sequence.end())
            {
                ++j;
                count++;
            }
            longestLength = max(longestLength, count);
        }
    }
    return longestLength;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 5, 6}; // Output = 3
    vector<int> nums = {1, 0, 0, 2, 3, 4}; // Output = 5
    cout << longestConsequence(nums) << endl;
    return 0;
}