class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = matrix.size();
        if(m == 0) 
        {
            return;
        }
        int n = matrix[0].size();
        if(n == 0)
        {
            return;
        }
        
        int i,j;
        int col0 = 1;
        int row0 = 1;
        for(i = 0,j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                row0 = 0;
                break;
            }
        }
        for(i = 0, j = 0; i < m; i++)
        {
            if(matrix[i][j] == 0)
            {
                col0 = 0;
                break;
            }
        }
        for(i = 1; i < m ;i++)
            for(j = 1; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
            
            
        for(j = 1; j < n; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(i = 1; i < m; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(j = 1; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        if(row0 == 0)
        {
            for(i = 0,j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
        if(col0 == 0)
        {
            for(j = 0,i = 0; i < m; i++)
            {
                matrix[i][j] = 0;
            }
        }
        
    }
};