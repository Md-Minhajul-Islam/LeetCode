// Q: https://leetcode.com/problems/flood-fill/description/
class Solution
{
public:
    typedef pair<int, int> pii;
    vector<pii> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    bool visited[52][52];
    int prevClr;
    void dfs(vector<vector<int>> &image, int i, int j, int color)
    {
        visited[i][j] = 1;
        image[i][j] = color;
        for (pii vpair : direction)
        {
            int vi = i + vpair.first;
            int vj = j + vpair.second;
            if (vi >= 0 && vi < m && vj >= 0 && vj < n && !visited[vi][vj] && image[vi][vj] == prevClr)
            {
                dfs(image, vi, vj, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        m = image.size(), n = image[0].size();
        prevClr = image[sr][sc];
        dfs(image, sr, sc, color);
        return image;
    }
};