class Solution {
public:
    int getKth(int A[], int lenA, int B[], int lenB, int k)
    {
        //this 2 first, before k == 1,because there may be no A[0] or B[0]
        //assume lenA>=lenB
        if(lenB > lenA)
        {
            return getKth(B,lenB,A,lenA,k);
        }
        if(lenB == 0)
        {
            return A[k-1];
        }
        
        if(k == 1)//!!!!!!!
        {
            return A[0] > B[0] ? B[0]:A[0];
        }
        
        
        
        int pb = (k-2)/2 > lenB-1? lenB-1:(k-2)/2;///len-1!!!
        int pa = k-2 - pb;
        if(A[pa] > B[pb])
        {
            return getKth(A,pa+1,B+pb+1,lenB-pb-1,k-pb-1);
        }
        else
        {
            return getKth(A+pa+1,lenA-pa-1,B,pb+1,k-pa-1);
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if((m+n)%2 == 0)
        {
            int num1 = getKth(A,m,B,n,(m+n)/2);
            int num2 = getKth(A,m,B,n,(m+n)/2+1);
            return (double)(num1+num2)/2.0;
        }
        else
        {
            return getKth(A,m,B,n,(m+n)/2+1);
        }
       
    }
};