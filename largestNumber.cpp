#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
// Timecomplexity O(nlogn) Space complexity O(n)
string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), compare);
    string result = "";
    for (int i = 0; i < nums.size(); ++i)
    {
        result += to_string(nums[i]);
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums);
    return 0;
}