class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int left = 0;
        int right = n - 1;
        int mid;
        bool find;
        while(left <= right)
        {
            mid =  (left+right)/2;
            if(A[mid] == target)
            {
                return mid;
            }
            else
            {
                find = false;
                if(mid+1 < right)
                {
                    if(A[mid+1] <= target && target <= A[right] || (A[mid+1] <= target || target <= A[right]) && A[right] <= A[mid+1])
                    {
                        left = mid+1;
                        find = true;
                    }
                }
                if(left < mid-1)
                {
                    if(A[left] <= target && target <= A[mid-1] || (A[left] <= target || target <= A[mid-1]) && A[mid-1] <= A[left])
                    {
                        right = mid-1;
                        find = true;
                    }
                }
                if(!find)
                {
                    if(mid+1 == right && target == A[right])
                    {
                        return right;
                    }
                    if(left == mid-1 && target == A[left])
                    {
                        return left;   
                    }
                    return -1;
                }
            }
        }
        return -1;
    }
};