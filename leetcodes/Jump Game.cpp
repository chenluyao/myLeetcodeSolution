class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0)
        {
            return false;
        }
        if(n == 1)
        {
            return true;
        }
        int i;
        int maxLen = 0;
        
        for(i = 0; i < n; i++)
        {
            if(A[i] != 0)
            {
                if(A[i]+i > maxLen)
                {
                    maxLen = A[i]+i;
                }
            }
            else
            {
                if(maxLen > i ||maxLen == i && i == n-1 )//can jump over
                {
                    //do nothing
                }
                else 
                {
                    return false;
                }
            }
        }
        if(maxLen >= n-1)
        {
            return true;
        }
        return false;
    }
};