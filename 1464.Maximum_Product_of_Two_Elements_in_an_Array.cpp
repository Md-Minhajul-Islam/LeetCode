// Q: https : // leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};