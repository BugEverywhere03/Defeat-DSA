#include <iostream>
#include "TreeNode.cpp";
using namespace std;

bool isValidBST(TreeNode *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    return helpCheck(root, LONG_MIN, LONG_MAX);
}
bool helpCheck(TreeNode *root, long minVal, long maxVal)
{
    if (root == NULL)
        return true;
    if (root->val > minVal && root->val < maxVal)
        return helpCheck(root->left, minVal, root->val) && helpCheck(root->right, root->val, maxVal);
    return false;
}

int main()
{
    
}