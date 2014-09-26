class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = matrix.size();
        if(n == 0 || n == 1)
        {
            return;
        }
        int len = n;
        vector<int> save;
        int i;
        int level = 0;
        int temp;
        while(len >= 2)
        {
            save.clear();
            for(i=level; i<n-level-1; i++)
            {
                
                save.push_back(matrix[level][i]);
            }
            for(i=level; i<n-level-1; i++)
            {
                temp = matrix[i][n-level-1];
                matrix[i][n-level-1] = save[i-level];
                save[i-level] = temp;
            }
            for(i = n-level-1; i > level; i--)
            {
                temp = matrix[n-level-1][i];
                matrix[n-level-1][i] = save[n-level-1-i];
                save[n-level-1-i] = temp;
            }
            for(i = n-level-1; i > level; i--)
            {
                temp = matrix[i][level];
                matrix[i][level] = save[n-level-1-i];
                save[n-level-1-i] = temp;
            }
            for(i=level; i<n-level-1; i++)
            {
                temp = matrix[level][i];
                matrix[level][i] = save[i-level];
                save[i-level] = temp;
            }
            
        
            len = len - 2;
            level++;
        }
        
        
        
    }
};