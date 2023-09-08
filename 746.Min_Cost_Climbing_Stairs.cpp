// Q: https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
class Solution
{
public:
    int minClimb(int n, vector<int> &cost, vector<int> &dp)
    {
        if (n <= 1)
            return dp[n] = cost[n];
        if (dp[n] != -1)
            return dp[n];
        int pick = minClimb(n - 1, cost, dp);
        int nonPick = minClimb(n - 2, cost, dp);
        return dp[n] = cost[n] + min(pick, nonPick);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(minClimb(n - 1, cost, dp), minClimb(n - 2, cost, dp));
    }
};