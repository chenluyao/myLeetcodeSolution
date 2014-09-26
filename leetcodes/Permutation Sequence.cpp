class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string s;
        if(n == 0|| k == 0)
        {
            return "";
        }
        
        char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
        int exp =1;
        int i;
        for(i = 1; i <= n; i++)
        {
            exp = exp * i;//n!
        }
        int index;
        int base = n;
        while(base >= 1)
        {
            k = (k-1)%exp+1;
            exp = exp/base;
            base --;
            index = (k-1)/exp+1;
            int j=0;
            while(index > 0)//the index-th num not taken
            {
                j++;
                if(num[j] != '@')
                {
                    index--;
                }
            }
            s.append(1,num[j]);
            num[j] = '@';
        }
        return s;
        
    }
};