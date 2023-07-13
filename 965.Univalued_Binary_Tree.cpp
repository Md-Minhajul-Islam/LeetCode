// Q: https://leetcode.com/problems/univalued-binary-tree/description/
class Solution
{
public:
    bool preorderTraverse(TreeNode *root, int value)
    {
        if (root == NULL)
            return true;
        if (root->val != value)
            return false;
        return preorderTraverse(root->left, value) && preorderTraverse(root->right, value);
    }
    bool isUnivalTree(TreeNode *root)
    {
        int value = root->val;
        return preorderTraverse(root, value);
    }
};