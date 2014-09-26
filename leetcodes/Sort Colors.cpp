class Solution {
public:
    void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n < 2)
        {
            return;
        }
        int p1 = 0;
        int p2 = 0;
        int p3 = n-1;
        //0:(,p1)
        //1:[p1,p2)
        //undone:[p2,p3]
        //2:(p3,)
        for(p2 = 0; p2 <= p3; )
        {
            if(A[p2] == 0)
            {
                int temp = A[p1];//A[p1] may not be 1, eg initial
                A[p1] = 0;
                A[p2] = temp;
                p1++;
                p2++;
            }
            else if(A[p2] == 1)
            {
                p2++;
            }
            else if(A[p2] == 2)
            {
                int temp = A[p3];
                A[p3] = 2;
                A[p2] = temp;
                p3--;
            }
        }
        
    }
};