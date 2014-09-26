class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0)
        {
            return 0;
        }
        int i;
        int read;
        int write = 0;
        
        for(read = 0; read < n; read++)
        {
            if(A[read] != elem)
            {
                A[write++] = A[read];
            }
        }
        return write;
    }
};