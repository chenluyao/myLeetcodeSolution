class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int direction;//0,1,2,3
        vector<vector<int> > result;
        //0:left->right
        //1:up->down
        //2:right->left
        //3:down->up
        if(n == 0)
        {
            return result;
        }
        int i; 
        int j;
        vector<int> r;
        for(j = 0; j < n; j++)
        {
            r.push_back(-1);
        }
        for(i = 0; i < n; i++)
        {
            
            result.push_back(r);
        }
        
        int rleft = 0;
        int rright = n - 1;
        int cup = 0;
        int cdown = n - 1;
        direction = 0;
        
        int num = 1;
        while(rleft <= rright && cup <= cdown)
        {
            if(direction == 0)
            {
                i = cup;
                for(j = rleft; j<= rright; ++j)
                {
                    result[i][j]= num++;
                }
                cup++;
            }
            else if(direction == 1)
            {
                j = rright;
                for(i = cup; i <= cdown; ++i)
                {
                    result[i][j]= num++;
                }
                rright--;
            }
            else if(direction == 2)
            {
                i = cdown;
                for(j = rright; j >= rleft; --j)
                {
                    result[i][j]= num++;
                }
                cdown --;
            }
            else
            {
                j = rleft;
                for(i = cdown; i >= cup; --i)
                {
                    result[i][j]= num++;
                }
                rleft++;
            }
            direction = (direction+1)%4;
        }
        return result;
        
    }
};