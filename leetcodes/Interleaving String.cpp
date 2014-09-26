class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if(s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        int m = s1.size();
        int n = s2.size();
        
        bool ** table = new bool*[m+1];
        int i;
        for(i = 0; i < m+1; i++)
        {
            table[i] = new bool[n+1];
        }
        
        table[0][0] = true;
        for(i = 1; i < m+1; i++)
        {
            table[i][0] = table[i-1][0]&&(s1[i-1] == s3[i-1]);
        }
        for(i = 1; i < n+1; i++)
        {
            table[0][i] = table[0][i-1]&&(s2[i-1] == s3[i-1]);
        }
        
        int j;
        for(i = 1; i < m+1; i++)
        {
            for(j = 1; j < n+1; j++)
            {
                table[i][j] = table[i-1][j]&&(s1[i-1] == s3[i+j-1])||table[i][j-1]&&(s2[j-1] == s3[i+j-1]);
            }
        }
        return table[m][n];
    }
};