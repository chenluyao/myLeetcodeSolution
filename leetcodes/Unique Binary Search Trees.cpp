class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0 || n == 1)
        {
            return 1;
        }
        int * result = new int[n+1];
        int i;
        for(i = 0 ; i <= n; i++)
        {
            result[i] = 0;
        }
        result[0] = 1;
        result[1] = 1;
        int j;
        for(j = 2; j<= n ; j++)
        {
            for(i = 0; i < j; i ++)
            {
                result[j] += result[i] *result[j-i-1];
            }
        }
        int r = result[n];
        
        delete result;
        return r;
    }
};