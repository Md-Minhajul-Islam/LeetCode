// Q: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
class Solution
{
public:
    void arrayToBST(TreeNode *&root, vector<int> nums, int l, int r)
    {
        if (l > r)
            return;
        int mid = (l + r) / 2;
        root = new TreeNode(nums[mid]);
        arrayToBST(root->left, nums, l, mid - 1);
        arrayToBST(root->right, nums, mid + 1, r);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = NULL;
        arrayToBST(root, nums, 0, nums.size() - 1);
        return root;
    }
};