class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int one = 0;
        int two = 0;
        int notthree;
        int i;
        for(i = 0; i < n; ++i)
        {
            int x = A[i];
            
            two = two ^ (one & x);
            one = one ^ x;
            notthree = ~(one & two);
            one = one & notthree;
            two = two & notthree;
        }
        return one;
    }
};