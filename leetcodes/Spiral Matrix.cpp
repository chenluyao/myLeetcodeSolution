class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int direction;//0,1,2,3
        vector<int> result;
        //0:left->right
        //1:up->down
        //2:right->left
        //3:down->up
        int m = matrix.size();
        if(m == 0)
        {
            return result;
        }
        int n = matrix[0].size();
        if(n == 0)
        {
            return result;
        }
        
        int rleft = 0;
        int rright = n - 1;
        int cup = 0;
        int cdown = m - 1;
        direction = 0;
        int i;
        int j;
        while(rleft <= rright && cup <= cdown)
        {
            if(direction == 0)
            {
                i = cup;
                for(j = rleft; j<= rright; ++j)
                {
                    result.push_back(matrix[i][j]);
                }
                cup++;
            }
            else if(direction == 1)
            {
                j = rright;
                for(i = cup; i <= cdown; ++i)
                {
                    result.push_back(matrix[i][j]);
                }
                rright--;
            }
            else if(direction == 2)
            {
                i = cdown;
                for(j = rright; j >= rleft; --j)
                {
                    result.push_back(matrix[i][j]);
                }
                cdown --;
            }
            else
            {
                j = rleft;
                for(i = cdown; i >= cup; --i)
                {
                    result.push_back(matrix[i][j]);
                }
                rleft++;
            }
            direction = (direction+1)%4;
        }
        return result;
        
        
    }
};