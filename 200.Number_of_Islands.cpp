// Q: https://leetcode.com/problems/number-of-islands/description/
class Solution
{
public:
    typedef pair<int, int> pii;
    vector<pii> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool visited[305][305];
    void dfs(vector<vector<char>> &grid, int i, int j, int r, int c)
    {
        visited[i][j] = 1;
        for (pii vpair : direction)
        {
            int vi = i + vpair.first;
            int vj = j + vpair.second;
            if (vi >= 0 && vi < r && vj >= 0 && vj < c && !visited[vi][vj] && grid[vi][vj] == '1')
            {
                dfs(grid, vi, vj, r, c);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                dfs(grid, i, j, r, c);
                ++cnt;
            }
        return cnt;
    }
};