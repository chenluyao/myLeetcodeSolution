class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = grid.size();
        if(m == 0)
        {
            return 0;
        }
        int n = grid[0].size();
        if(n == 0)
        {
            return 0;
        }
        int i;
        int j;
        
        for(i = 1; i < n; i++)
        {
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }
        for(i = 1; i < m; i++)
        {
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
            {
                int temp1 = grid[i][j] + grid[i-1][j];
                int temp2 = grid[i][j] + grid[i][j-1];
                grid[i][j] = temp1 > temp2? temp2: temp1;
            }
        return grid[m-1][n-1];
    }
};