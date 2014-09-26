class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0)
        {
            return 0;
        }
        
        int storeStart = -1;
        int storeSum = 0;
        int start= -1;
        int end= -1;
        int i;
        int sum;
        for(i = 0; i < n; i++)
        {
            if(A[i] >= 0)
            {
                end = i;
                if(start == -1)
                {
                    start = i;
                    sum = A[i];
                }
                else
                {
                    sum = A[i] + sum;
                }
            }
            else if(A[i] < 0 && start != -1)
            {
                if(A[i] + sum >= 0)
                {
                    sum = A[i] + sum;
                    end = i;
                }
                else
                {
                    start = -1;
                    end = -1;
                    sum = 0;
                }
            }
            if(start != -1 && end != -1)
            {
                if(sum > storeSum)
                {
                    storeSum = sum;
                    storeStart = start;
                }
            }
        }
        if(storeSum == 0 && storeStart == -1)
        {
            int intN = A[0];
            for(i = 1; i < n; i++)
            {
                if(A[i] > intN)
                {
                    intN = A[i];
                }
            }
            storeSum = intN;
        }
        
        return storeSum;
    }
};