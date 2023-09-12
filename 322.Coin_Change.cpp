// Q: https://leetcode.com/problems/coin-change/description/
class Solution
{
public:
    const int INF = 1e8;
    int dp[15][10004];
    int coinChange2(int n, int s, vector<int> &coins)
    {
        if (s == 0)
            return 0;
        if (n < 0)
            return INF;
        if (dp[n][s] != -1)
            return dp[n][s];
        if (s >= coins[n])
            return dp[n][s] = min(1 + coinChange2(n, s - coins[n], coins), coinChange2(n - 1, s, coins));
        return dp[n][s] = coinChange2(n - 1, s, coins);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = coinChange2(n - 1, amount, coins);
        if (ans == INF)
            return -1;
        else
            return ans;
    }
};