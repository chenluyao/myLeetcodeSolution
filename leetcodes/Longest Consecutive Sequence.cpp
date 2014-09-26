class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        set<int> setNum;
        int m = num.size();
        int i;
        for(i = 0; i < m; i++)
        {
            setNum.insert(num[i]);
        }
        int len = 1;
        int maxLen = 1;
        for(i = 0; i < m; i++)
        {
            int n = num[i];
            if(setNum.find(n+1) != setNum.end() && setNum.find(n-1) == setNum.end())
            {   
                len = 2;
                n++;
                while(setNum.find(n+1) != setNum.end())
                {
                    len++;
                    n++;
                }
                if(len > maxLen)
                {
                    maxLen = len;
                }
            }
        }
        return maxLen;
    }
};