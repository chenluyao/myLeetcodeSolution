class Solution {
public:
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if(nRows == 0)
        {
            return "";
        }
        if(nRows == 1)
        {
            return s;
        }
        int i;
        int n = s.size();
        if(n == 0)
        {
            return s;
        }
        string result;
        int j;

        for(i = 0 ; i < nRows; i++)
        {
            //0 ; n-1
            //(i, 2n-i)
            for(j = 0; j < n; j++)
            {
                if((i == 0 || i == nRows-1) && j %(2*nRows -2)== i)
                {
                    result.append(1,s[j]);
                }
                else if(j %(2*nRows -2)== i || j %(2*nRows -2) == 2*nRows -2 - i)
                {
                    result.append(1,s[j]);
                }
            }
        }
        return result;
    }
};