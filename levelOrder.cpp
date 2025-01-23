#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

// Solution using Queue
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> vec;
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            vec.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        result.push_back(vec);
    }
    return result;
}

// Solution using Recursion
vector<vector<int>> levelOrderRecursion(TreeNode *root)
{
    vector<vector<int>> result;
    helpLevelOrder(root, result, 0);
    return result;
}

void helpLevelOrder(TreenNode *root, vector<vector<int>> &result, int level)
{
    if (root == NULL)
        return;
    if (result.size() <= level)
    {
        result.push_back(vector<int>());
    }
    result[level].push_back(root->val);
    helpLevelOrder(root->left, result, level + 1);
    helpLevelOrder(root->right, result, level + 1);
}

int main()
{
    return 0;
}