class Solution {
public:
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
       int m = S.size();
       int n = T.size();
       if(m == 0 || n == 0)
       {
           return 0;
       }
       int ** table = new int*[n+1];
       int i;
       for(i = 0; i< n+1; i++)
       {
           table[i] = new int[m+1];
           table[i][m] = 0; 
       }
       for(i = 0; i < m+1; i++)
       {
           table[n][i] = 1;
       }
       
       
      
       int j;
       
       for(i = n-1; i >=0 ; i--)
       {
           for(j = m-1; j >=0 ; j--)
           {
               if(T[i] == S[j])
               {
                   table[i][j] = table[i+1][j+1] + table[i][j+1];
               }
               else
               {
                   table[i][j] = table[i][j+1];
               }
           }
       }
       return table[0][0];
        
    }
};