#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// Timecomplexity O(n^2) Space complexity O(n)
// vector<vector<int>> merge(vector<vector<int>> &internals)
// {
//     vector<vector<int>> result;
//     vector<int> vec;
//     for (int i = 0; i < internals.size(); ++i)
//     {
//         int left = internals[i][0];
//         int right = internals[i][1];
//         while (left <= right)
//         {
//             vec.push_back(left);
//             ++left;
//         }
//     }
//     sort(vec.begin(), vec.end());
//     int start = 0;
//     int end = start + 1;
//     while (end < vec.size())
//     {
//         while (end < vec.size() && ((vec[end] == vec[end - 1] + 1) || (vec[end] == vec[end - 1])))
//         {
//             ++end;
//         }
//         vector<int> temp = {vec[start], vec[end - 1]};
//         result.push_back(temp);
//         start = end;
//         ++end;
//     }
//     return result;
// }
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (end >= intervals[i][0] || intervals[i][0] <= end)
        {
            end = max(intervals[i][1], end);
        }
        else
        {
            vector<int> temp = {start, end};
            result.push_back(temp);
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    result.push_back(vector<int>{start, end});
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {0, 6}, {8, 12}};
    vector<vector<int>> result = merge(intervals);
    for (vector<int> v : result)
    {
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}