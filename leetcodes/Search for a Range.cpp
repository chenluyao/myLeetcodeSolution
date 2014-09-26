class Solution {
public:
    vector<int> subSearchRange(int A[], int start,int end, int target)
    {
        vector<int> result;
        if(end < start || end == start && A[end] != target)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        if(A[start] == A[end] && A[start] == target)//insurance of O(log n)
        {
            result.push_back(start);
            result.push_back(end);
            return result;
        }
        //result.push_back(-1);
        //result.push_back(-1);
        int mid = (start+end)/2;
        vector<int> result1;
        vector<int> result2;
        if(A[mid] > target)
        {
            return subSearchRange(A,start, mid-1, target);
        }
        else if(A[mid] < target)
        {
            return subSearchRange(A,mid+1, end, target);
        }
        else
        {
            result1 = subSearchRange(A,start, mid-1, target);
            result2 = subSearchRange(A,mid+1, end, target);
            result.push_back(mid);
            result.push_back(mid);
            if(result1[0] != -1)
            {
                result[0] = result1[0];
            }
            if(result2[1] != -1)
            {
                result[1] = result2[1];
            }
            return result;
        }
        
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return subSearchRange(A, 0,n-1, target);
    }
};