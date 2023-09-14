// Q: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution
{
public:
    int dp[505][505];
    int lcs(string &a, string &b, int n, int m)
    {
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (a[n] == b[m])
            return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1);
        else
            return dp[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    }
    int minInsertions(string s)
    {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return n - lcs(s, s1, n - 1, n - 1);
    }
};