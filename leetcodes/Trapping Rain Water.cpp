class Solution {
public:
    int trap(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n < 2)
        {
            return 0;
        }
        int i;
        int *maxAfterI = new int[n-1];
        maxAfterI[n-2] = n-1;
        for(i = n-3; i >= 0; --i)
        {
            maxAfterI[i] = A[i+1] > A[maxAfterI[i+1]] ? i+1 : maxAfterI[i+1];
        }
        int h = 0;
        int sum = 0;
        for(i = 0; i < n-1; i++)
        {
            int tempH = A[maxAfterI[i]] < A[i] ? A[maxAfterI[i]] : A[i];
            if(A[maxAfterI[i]] >= h && h >= tempH)
            {}
            else
            {
                h = tempH;
            }
            
            sum += h - A[i] > 0? h - A[i] : 0;
        }
        delete []maxAfterI;
        return sum;
    
    }
};