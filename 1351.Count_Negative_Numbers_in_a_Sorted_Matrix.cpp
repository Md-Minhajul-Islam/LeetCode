class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int j = 0;
        for(int i = grid.size()-1; i >= 0; i--)
        {
            while(j < grid[i].size())
            {
                if(grid[i][j] < 0)
                {
                    count += grid[i].size()-j;
                    break;
                }
                else j++;
            }
        }
        return count;
    }
};