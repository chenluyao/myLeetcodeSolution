class Solution {
public:
    bool isvalid(string &s, int start, int end)
    {
        if(end - start >2)
        {
            return false;
        }
        if(end - start ==0)
        {
            return true;
        }
        else if(end - start == 1 && s[start] != '0')
        {
            return true;
        }
        else
        {
            if(s[start] == '2' && (s[start+1] < '5'||(s[start+1] =='5' &&s[start+2] <='5'))||s[start] == '1')
            {
                return true;
            }
            return false;
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        int m;
        m = s.size();
        if(m < 4)
        {
            return result;
        }
        
        int i;
        int j;
        int k;
        int w;
        string newS[4] = {};
        for(i = 0; i <= 2; i++)
        {
            if(isvalid(s,0,i))
            {
                newS[0] = s.substr(0,i+1);
            
            
                for(j = i+1; j <= i+3 && j < m; j++)
                {
                    if(isvalid(s,i+1,j))
                    {
                        newS[1] = s.substr(i+1,j-i);
                   
                        for(k = j+1; k<= j+3 && k < m; k++)
                        {
                            if(isvalid(s,j+1,k) && isvalid(s,k+1,m-1))
                            {
                                newS[2] = s.substr(j+1,k-j);
                                newS[3] = s.substr(k+1,m-k-1);
                                string newStr = newS[0]+"."+newS[1]+"."+newS[2]+"."+newS[3];
                                result.push_back(newStr);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};