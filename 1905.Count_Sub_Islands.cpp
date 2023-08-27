// Q: https://leetcode.com/problems/count-sub-islands/description/
class Solution
{
public:
    typedef pair<int, int> pii;
    vector<pii> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool visited[503][503];
    bool flag;
    int n, m;
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        visited[i][j] = 1;
        if (!grid1[i][j])
            flag = 0;
        for (pii vpair : direction)
        {
            int vi = i + vpair.first;
            int vj = j + vpair.second;
            if (vi >= 0 && vi < m && vj >= 0 && vj < n && !visited[vi][vj] && grid2[vi][vj])
                dfs(grid1, grid2, vi, vj);
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int cnt = 0;
        m = grid1.size(), n = grid1[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] || !grid2[i][j])
                    continue;
                flag = 1;
                dfs(grid1, grid2, i, j);
                if (flag)
                    cnt++;
            }
        return cnt;
    }
};