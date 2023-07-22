// Q: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
class Solution
{
public:
    vector<int> v;
    void values(TreeNode *root)
    {
        if (root == NULL)
            return;
        v.push_back(root->val);
        values(root->left);
        values(root->right);
    }
    bool findAnother(TreeNode *root, int n)
    {
        if (root == NULL)
            return false;
        if (root->val == n)
            return true;
        if (root->val < n)
            return findAnother(root->right, n);
        else
            return findAnother(root->left, n);
    }
    bool findTarget(TreeNode *root, int k)
    {
        values(root);
        for (int i = 0; i < v.size(); i++)
        {
            bool flag = findAnother(root, k - v[i]);
            if (flag && (k - v[i]) != v[i])
                return true;
        }
        return false;
    }
};