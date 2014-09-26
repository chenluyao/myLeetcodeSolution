class Solution {
public:
    int min(int a, int b)
    {
        return a>b?b:a;
    }
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = strs.size();
        if(m == 0)
        {
            return "";
        }
        string str = strs[0];
        int i;
        int j;
        for(i = 1; i < m; i++)
        {
            j = 0;
            for(j = 0; j < min((int)str.size(),(int)strs[i].size()); j++)
            {
                if(str[j] != strs[i][j])
                {
                    break;
                }
            }
            str = str.substr(0,j);
        }
        return str;
    }
};