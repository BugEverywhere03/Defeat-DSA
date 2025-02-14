#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>
#include "TreeNode.cpp"
using namespace std;

// TreeNode *build(queue<int> &listNode, vector<int> &inorder, int start, int end)
// {
//     if (!listNode.empty() && start > end)
//         return nullptr;
//     int rootIndex = -1;
//     int rootValue = listNode.front();
//     listNode.pop();
//     if (start == end)
//         return new TreeNode(rootValue);
//     for (int i = start; i <= end; i++)
//     {
//         if (inorder[i] == rootValue)
//         {
//             rootIndex = i;
//             break;
//         }
//     }
//     if (rootIndex == -1)
//         return nullptr;
//     TreeNode *root = new TreeNode(rootValue);
//     root->left = build(listNode, inorder, start, rootIndex - 1);
//     root->right = build(listNode, inorder, rootIndex + 1, end);
//     return root;
// }
TreeNode *build(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> mapIndex, int &currIndex, int start, int end)
{
    if (start > end)
        return nullptr;
    if (currIndex == preorder.size())
        return nullptr;
    int val = preorder[++currIndex];
    int valIndex = mapIndex[val];
    TreeNode *root = new TreeNode(val);
    if (start == end)
        return root;
    root->left = build(preorder, inorder, mapIndex, currIndex, start, valIndex - 1);
    root->right = build(preorder, inorder, mapIndex, currIndex, valIndex + 1, end);
    return root;
}
// Using Queue and Recursion
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mapIndex;
    for (int i = 0; i < inorder.size(); ++i)
    {
        mapIndex[inorder[i]] = i;
    }
    int currIndex = 0;
    return build(preorder, inorder, mapIndex, currIndex, 0, inorder.size() - 1);
}

int main()
{
}
