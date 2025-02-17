#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Using quick sort algorithm
int longestConsequence(vector<int> &nums)
{
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
            longestLength = max(longestLength, currLength);
            currLength = 1;
        }
        longestLength = max(longestLength, currLength);
    }
    return longestLength;
}

int main()
{
    vector<int> nums = {1, 2, 3, 5, 6, 4}; // Output = 4
    cout << longestConsequence(nums) << endl;
    return 0;
}