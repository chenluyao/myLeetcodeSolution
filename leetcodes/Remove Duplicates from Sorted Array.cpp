class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n < 2)
        {
            return n;
        }
        int readPoint = 1;
        int writePoint = 1;
        while(readPoint < n)
        {
            int num = A[readPoint];
            if(A[writePoint-1] == num)
            {
                //do nothing
            }
            else
            {
                A[writePoint] = num;
                writePoint ++;
            }
            readPoint ++;
        }
        return writePoint;
    }
};