#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

vector<string> findRelativeRanks(vector<int> &nums)
{
    unordered_map<int, int> position;
    priority_queue<int> heap;
    for (int i = 0; i < nums.size(); ++i)
    {
        heap.push(nums[i]);
        position[nums[i]] = i;
    }
    vector<string> result(5);
    int rank = 1;
    while (!heap.empty())
    {
        int tmp = heap.top();
        string place = "";
        if (rank == 1)
            place = "Gold Medal";
        if (rank == 2)
            place = "Silver Medal";
        if (rank == 3)
            place = "Bronze Medal";
        if (rank == 4)
            place = "4";
        if (rank == 5)
            place = "5";
        result[position[heap.top()]] = place;
        ++rank;
        heap.pop();
    }
    return result;
}
vector<string> solution_2(vector<int> &scores)
{
    priority_queue<pair<int, int>> rank_sorted;
    for (int i = 0; i < scores.size(); ++i)
    {
        rank_sorted.push({scores[i], i});
    }
    vector<string> ranks(scores.size());
    int rank = 1;
    while (!rank_sorted.empty())
    {
        int index = rank_sorted.top().second;
        rank_sorted.pop();
        string place = "";
        if (rank == 1)
            place = "Gold Medal";
        if (rank == 2)
            place = "Silver Medal";
        if (rank == 3)
            place = "Bronze Medal";
        if (rank > 3)
            place = to_string(rank);
        ranks[index] = place;
        ++rank;
    }
    return ranks;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 8, 0, 7, 20};
    vector<string> ranking = solution_2(nums);
    for (string s : ranking)
    {
        cout << s << endl;
    }
    return 0;
}