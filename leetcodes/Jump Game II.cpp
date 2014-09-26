class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //greedy
        if(n == 1)
        {
            return 0;
        }
        int start = 0;
        int end = 0;
        int i;
        int count = 0;//
        int max;
        while(end < n)//!
        {
            count ++;
            max = A[0];//
            for(i = start; i<= end; i++)
            {
                
                if(A[i]+i >= n-1)
                {
                    return count;
                }
                if(A[i]+i > max)
                {
                    max = A[i]+i;
                }
            }
            start = end +1;
            end = max;
        }
        return count;
        
        
    }
};