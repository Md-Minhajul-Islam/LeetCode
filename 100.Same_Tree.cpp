class Solution
{
public:
    vector<int> v;
    // Q: https://leetcode.com/problems/same-tree/description/
    void treeTraverse(TreeNode *root)
    {
        if (root == NULL)
        {
            v.push_back(-100000);
            return;
        }
        v.push_back(root->val);
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        treeTraverse(p);
        vector<int> v1(v);
        v.clear();
        treeTraverse(q);
        vector<int> v2(v);
        return v1 == v2;
    }
};