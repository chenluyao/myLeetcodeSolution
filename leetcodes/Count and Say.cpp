class Solution {
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0)
        {
            return "";
        }
        string s="1";
        string re;
        int i;
        int j;
        for(i = 2; i <= n; i++)
        {
            re = "";
            char cur = s[0];
            int count = 1;
            for(j = 1; j < s.size(); j++)
            {
                if(s[j] != cur)
                {
                  
                    re.append(1,'0'+count);
                    re.append(1,cur);
                    cur = s[j];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            re.append(1,'0'+count);
            re.append(1,cur);
            s= re;
        }
        return s;
    }
};