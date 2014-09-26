class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = obstacleGrid.size();
        if(m == 0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n == 0)
        {
            return 0;
        }
        int i;
        int j;
        int ** matrix = new int*[m];
        for(i = 0; i < m ; i++)
        {
            matrix[i] = new int[n];
        }
        matrix[0][0] = 1-obstacleGrid[0][0];
        for(i = 0, j = 1; j < n; j++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = matrix[i][j-1];
            }
        }
        for(j = 0, i = 1; i < m; i++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = matrix[i-1][j];
            }
        }
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                }
            }
        int result =  matrix[m-1][n-1];
        
        for(i = 0; i < m ; i++)
        {
            delete matrix[i];
        }
        delete matrix;
        return result;
    }
};