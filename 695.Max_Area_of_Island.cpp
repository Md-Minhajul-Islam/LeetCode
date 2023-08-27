// Q: https://leetcode.com/problems/max-area-of-island/description/
class Solution
{
public:
    typedef pair<int, int> pii;
    vector<pii> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int m, n, area;
    bool visited[52][52];
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        visited[i][j] = 1;
        area++;
        for (pii vpair : direction)
        {
            int vi = i + vpair.first;
            int vj = j + vpair.second;
            if (vi >= 0 && vi < m && vj >= 0 && vj < n && !visited[vi][vj] && grid[vi][vj])
                dfs(grid, vi, vj);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                area = 0;
                if (visited[i][j] || grid[i][j] == 0)
                    continue;
                dfs(grid, i, j);
                maxArea = max(area, maxArea);
            }
        return maxArea;
    }
};