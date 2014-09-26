class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(n < 3)
        {
            return n;
        }
        int readPos;
        int writePos = 0;
        int len = n;
        for(readPos = 0; readPos < n; )
        {
            if(readPos > 0 &&A[readPos] == A[readPos-1])
            {
                readPos++;
                len--;
            }
            else
            {
                A[writePos] = A[readPos];
                readPos++;
                writePos ++;
                
                if(A[readPos] == A[readPos-1])
                {
                    A[writePos] = A[readPos];
                    readPos++;
                    writePos ++;
                }
            }
        }
        return len;
    }
};