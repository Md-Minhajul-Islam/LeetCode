// Q: https://leetcode.com/problems/longest-common-subsequence/description/
class Solution
{
public:
    int dp[1003][1003];
    int lcs(string &a, string &b, int n, int m)
    {
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (a[n] == b[m])
            return dp[n][m] = lcs(a, b, n - 1, m - 1) + 1;
        else
            return dp[n][m] = max(lcs(a, b, n, m - 1), lcs(a, b, n - 1, m));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        memset(dp, -1, sizeof(dp));
        return lcs(text1, text2, n - 1, m - 1);
    }
};