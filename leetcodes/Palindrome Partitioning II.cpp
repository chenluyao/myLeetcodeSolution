class Solution {
public:
    static const int intMax = 429496729;
    vector<vector<bool> > tableP;//
    //vector<vector<int> > tableC;//-1:not available,else:minC
    //map<int,int> mapC;
   /* bool palindrome(string s, int start,int end)
    {
        
        
        
            if(end - start == 1 )
            {
                tableP[start][end-1] = true;
                return true;
            }
            else
            {
                if(s[start]!=s[end-1])
                {
                    tableP[start][end-1] = false;
                    return false;
                }
                else
                {
                    if(start+1 <= end-2)//!!!
                    {
                        return palindrome(s, start+1, end -1);//has already been figured out
                    }
                    else//!!!!!T_T
                    {
                        tableP[start][end-1] = true;
                        return true;
                    }
                }
            
            }
        
    }
    */
    
    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.size();
        if(len < 2)
        {
            return 0;
        }
        int i;
        int * mapC = new int[len+1];//+1for easy calculate
        for(i = 0; i <= len; i++)
        {
            mapC[i] = len - 1 - i;
           // c.push_back(intMax);
        }
       
        tableP.clear();
        vector<bool> r;
        //vector<int> c;
       
        for(i = 0; i < len; i++)
        {
            r.push_back(false);
           // c.push_back(intMax);
        }
        for(i = 0; i < len; i++)
        {
            tableP.push_back(r);
          //  tableC.push_back(c);
        }
        
        int j;
        
        //[i,j]
        for(i = len - 1; i>=0; i--)
            for(j = i; j < len; j++)
            {
                if(s[i] == s[j] && (j - i < 2 || tableP[i+1][j -1]))
                {
                    tableP[i][j] = true;
                    int laterCut = mapC[j+1];//mapC[len]= 0;mapC[j+1]already calculated
                    if(laterCut + 1 < mapC[i])
                    {
                        mapC[i] = laterCut + 1;
                    }
                }
            }
        int result = mapC[0];
        delete mapC;
        return result;
        
    }
};