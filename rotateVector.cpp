#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

// void rotateVector(vector<int> &nums, int k)
// {
//     deque<int> queueDoule(nums.begin(), nums.end());
//     int count = 1;
//     while (count <= k)
//     {
//         int temp = queueDoule.back();
//         queueDoule.pop_back();
//         queueDoule.push_front(temp);
//         count++;
//     }
//     nums = vector<int>(queueDoule.begin(), queueDoule.end());
// }
void rotateVector(vector<int> &nums, int k)
{
    unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        hashMap[i] = nums[i];
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        int index = (i + k) % nums.size();
        nums[index] = hashMap[i];
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotateVector(nums, 3);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}