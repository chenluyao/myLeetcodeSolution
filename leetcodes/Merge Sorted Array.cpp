class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = m+n;
        int i;
        int j;
        for(i = m-1, j = n-1; i>=0 && j >= 0; )
        {
            if(A[i] > B[j])
            {
                A[--size] = A[i--];
            }
            else
            {
                A[--size] = B[j--];
            }
        }
        while(size > 0 && j >= 0)
        {
            A[--size] = B[j--];
        }
        
    }
};