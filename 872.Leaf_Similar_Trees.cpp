// Q: https://leetcode.com/problems/leaf-similar-trees/description/
class Solution
{
public:
    vector<int> v;
    void TreeLeaves(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            v.push_back(root->val);
        TreeLeaves(root->left);
        TreeLeaves(root->right);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        TreeLeaves(root1);
        vector<int> v1(v);
        v.clear();
        TreeLeaves(root2);
        vector<int> v2(v);
        return v1 == v2;
    }
};