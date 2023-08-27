// Q: https://leetcode.com/problems/as-far-from-land-as-possible/description/
class Solution
{
public:
    typedef pair<int, int> pii;
    int maxDistance(vector<vector<int>> &grid)
    {
        vector<pii> one, zero;
        int n = grid.size();
        int maxDis = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    one.push_back({i, j});
                else
                    zero.push_back({i, j});
            }
        for (pii zeroPair : zero)
        {
            int minDis = INT_MAX;
            for (pii onePair : one)
            {
                minDis = min(minDis, abs(zeroPair.first - onePair.first) + abs(zeroPair.second - onePair.second));
            }
            if (minDis != INT_MAX)
                maxDis = max(maxDis, minDis);
        }
        return maxDis;
    }
};