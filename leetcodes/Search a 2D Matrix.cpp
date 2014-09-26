class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = matrix.size();
        if(m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        if(n == 0)
        {
            return false;
        }
        
        //select row
        int rleft = 0;
        int rright = m-1;
        int rmid;
        int r;
        bool find = false;
        while(rleft <= rright && find == false)
        {
            rmid = (rleft+rright)/2;
            if(matrix[rmid][0] > target)
            {
                rright = rmid - 1;
            }
            else if(matrix[rmid][n-1] < target)
            {
                rleft = rmid + 1;
            }
            else 
            {
                find = true;
                r = rmid;
                break;
            }
        }
        if(find == false)
        {
            return false;
        }
        
        int cleft = 0;
        int cright = n - 1;
        int cmid;
        int c;
        find = false;
        while(cleft <= cright && find == false)
        {
            cmid = (cleft + cright)/2;
            if(matrix[r][cmid] == target)
            {
                return true;
            }
            else if(matrix[r][cmid] > target)
            {
                cright = cmid - 1;
            }
            else
            {
                cleft = cmid + 1;
            }
        }
        return false;
        
        
    }
};