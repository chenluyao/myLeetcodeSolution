class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(m == 0 || n ==0)
        {
            return 0;
        }
        int ** table = new int*[m];
        int i;
        int j;
        for(i = 0; i < m; i++)
        {
            table[i] = new int[n];
        }
        
        for(i = 0; i < n; i++)
        {
            table[0][i] = 1;
        }
        for(i = 0; i < m; i++)
        {
            table[i][0] = 1;
        }
        
        for(i = 1; i<m; i++)
            for(j = 1; j < n; j++)
            {
                table[i][j] = table[i-1][j] + table[i][j-1];
            }
            
        return table[m-1][n-1];
    }
};