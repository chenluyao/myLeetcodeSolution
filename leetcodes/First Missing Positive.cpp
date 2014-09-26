class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // assume n >= 2
        int i;
        int last;
        int temp;
        for(i = 0; i < n; i++)
        {
            if(A[i] != i+1)
            {
                last = A[i];
                while(true)
                {
                    if(last - 1 >= 0 && last - 1 < n)
                    {
                        temp = A[last - 1];
                        A[last - 1] = last;
                        if(last == temp)
                        {
                            break;
                        }
                        last = temp;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        for(i = 0; i < n; i++)
        {
            if(A[i] != i+1)
            {
                return i+1;
            }
        }
        return n+1;
        
    }
};