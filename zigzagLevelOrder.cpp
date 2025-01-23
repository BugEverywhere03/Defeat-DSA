#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.cpp"
#include <math.h>
#include <algorithm>
using namespace std;

// Using Recursion
void helpTravel(TreeNode *root, vector<vector<int>> &result, int level)
{
    if (root == NULL)
        return;
    if (result.size() <= level)
    {
        result.push_back(vector<int>());
    }
    result[level].push_back(root->val);
    helpTravel(root->left, result, level + 1);
    helpTravel(root->right, result, level + 1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    helpTravel(root, result, 0);
    for (int i = 1; i < result.size(); i += 2)
    {
        reverse(result[i].begin(), result[i].end());
    }
    return result;
}

// Using Queue
vector<vector<int>> zigzagLevelOrderQueue(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    while ()
}

int main()
{
    return 0;
}