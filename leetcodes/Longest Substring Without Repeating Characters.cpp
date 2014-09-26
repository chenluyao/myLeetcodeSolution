class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = s.size();
        if(m  <= 1)
        {
            return m;
        }
        map<char,int> last;
        int i;
        int start = 0;
        int end;
        int len = 1;
        for(i = 0; i < m; i++)
        {
            end = i;
            if(last.find(s[i]) == last.end() || last[s[i]] < start)
            {
                
            }
            else
            {
                start = last[s[i]]+1;
            }
            if(end - start +1 > len)
            {
                len = end - start +1;
            }
            last[s[i]] = i;
        }
        return len;
    }
};