// Q: https://leetcode.com/problems/root-equals-sum-of-children/description/
class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        return root->val == (root->left->val) + (root->right->val);
    }
};