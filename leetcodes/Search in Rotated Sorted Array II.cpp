class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int start = 0;
        int end = n -1;
        int mid;
        while(start <= end)
        {
            mid = (start+end)/2;
            if(A[mid] == target)
            {
                return true;
            }
            else if(A[start] <A[mid])
            {
                if(A[start] <= target && A[mid] > target)
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
            else if(A[end] >A[mid])
            {
                if(A[mid] < target && A[end] >= target)
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            else
            {
                if(A[start] == A[mid])
                {
                    start++;
                }
                if(A[end] == A[mid])
                {
                    end--;
                }
            }
        }
        return false;
    }
};