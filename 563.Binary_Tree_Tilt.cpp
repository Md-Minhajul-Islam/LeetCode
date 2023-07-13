// Q: https://leetcode.com/problems/binary-tree-tilt/description/
class Solution
{
public:
    int sum;
    int findSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int l = findSum(root->left);
        int r = findSum(root->right);
        sum += abs(l - r);
        return l + r + root->val;
    }
    int findTilt(TreeNode *root)
    {
        sum = 0;
        findSum(root);
        return sum;
    }
};