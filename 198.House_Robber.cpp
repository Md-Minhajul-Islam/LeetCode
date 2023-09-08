// Q: https://leetcode.com/problems/house-robber/description/
class Solution
{
public:
    int rob(int n, vector<int> &nums, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int op1 = rob(n - 2, nums, dp) + nums[n];
        int op2 = rob(n - 1, nums, dp);
        return dp[n] = max(op1, op2);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return rob(n - 1, nums, dp);
    }
};