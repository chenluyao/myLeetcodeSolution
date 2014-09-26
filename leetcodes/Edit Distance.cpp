class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = word1.size();
        int n = word2.size();
        int ** table = new int*[m+1];
        int i;
        for(i = 0; i < m+1; i++)
        {
            table[i] = new int[n+1];
        }
        for(i = 0; i < m+1; i++)
        {
            table[i][0] = i;
        }
        for(i = 0; i< n+1; i++)
        {
            table[0][i] = i;
        }
        int j;
        for(i = 1; i < m+1; i++)
            for(j = 1; j < n+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    table[i][j] = table[i-1][j-1];
                }
                else
                {
                    int temp = table[i-1][j];
                    if(temp > table[i-1][j-1])
                    {
                        temp = table[i-1][j-1];
                    }
                    if(temp > table[i][j-1])
                    {
                        temp = table[i][j-1];
                    }
                    table[i][j] = temp+1;
                    
                }
            }
        return table[m][n];
    }
};