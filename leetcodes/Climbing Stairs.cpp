class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //S[n] = S[n-1]+ S[n-2];
        if(n < 2)
        {
            return n;
        }
        int i;
        int* S = new int[n+1];
        S[1] = 1;
        S[0] = 1;
        for(i = 2; i <= n; ++i)
        {
            S[i] = S[i-1]+ S[i-2];
        }
        return S[n];
    }
};