#include <vector>
#include <iostream>
#include "Tree.h"
using namespace std;

void prevOrderTravel(TreeNode *root)
{
    if (!root)
    {
        cout << 0 << endl;
        return;
    }
    cout << root->val << endl;
    prevOrderTravel(root->left);
    prevOrderTravel(root->right);
}
// void backTracking(int startPos, vector<int> &nums, vector<vector<int>> &result)
// {
//     if (startPos == nums.size())
//         result.push_back(nums);
//     for (int i = startPos; i < nums.size(); ++i)
//     {
//         swap(nums[i], nums[startPos]);
//         backTracking(startPos + 1, nums, result);
//         swap(nums[i], nums[startPos]);
//     }
// }
// void insertBST(TreeNode *&root, int val)
// {
//     if (!root)
//     {
//         root = new TreeNode(val);
//         return;
//     }
//     if (val > root->val)
//         insertBST(root->right, val);
//     else
//         insertBST(root->left, val);
// }
// void createBST(TreeNode *&root, int pos, vector<int> &nums)
// {
//     if (pos == nums.size())
//         return;
//     insertBST(root, nums[pos]);
//     createBST(root, pos + 1, nums);
// }
// vector<TreeNode *> generateTrees(int n)
// {
//     int pos = 0;
//     vector<vector<int>> vecs;
//     vector<int> nums;
//     vector<TreeNode *> result;
//     for (int i = 1; i <= n; ++i)
//     {
//         nums.push_back(i);
//     }
//     backTracking(pos, nums, vecs);
//     for (vector<int> v : vecs)
//     {
//         TreeNode *root = NULL;
//         createBST(root, 0, v);
//         result.push_back(root);
//     }
//     return result;
// }
vector<TreeNode *> generate(int start, int end)
{
    if (start > end)
        return {NULL};
    vector<TreeNode *> allTree;
    for (int i = start; i <= end; ++i)
    {
        // Tạo tất cả cây con bên phải của root = i
        vector<TreeNode *> leftBrand = generate(start, i - 1);
        // Tạo tất cả cây con bên trái của root = i
        vector<TreeNode *> rightBrand = generate(i + 1, start);
        // Tạo tất cả cây có root là (i)
        for (TreeNode *leftNode : leftBrand)
        {
            for (TreeNode *rightNode : rightBrand)
            {
                TreeNode *currNode = new TreeNode(i);
                currNode->left = leftNode;
                currNode->right = rightNode;
                allTree.push_back(currNode);
            }
        }
    }
    return allTree;
}

vector<TreeNode *> generateTrees(int n)
{
    if (n == 0)
        return vector<TreeNode *>();
    return generate(1, n);
}

int main()
{
    int n = 3;
    vector<TreeNode *> result = generateTrees(3);
    for (TreeNode *node : result)
    {
        prevOrderTravel(node);
    }
    return 0;
}