class Solution {
public:
    string str;
    int canDecode(int pos, int len)// len = 1 or 2
    {
        char c1 = str[pos];
        if(len == 1)
        {
            if(c1 == '0')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else//len == 2
        {
            char c2 = str[pos+1];
            if(c1 == '0'||c1 >='3')
            {
                return 0;
            }
            else if(c1 == '2' && c2 >'6')
            {
                return 0;
            }
            return 1;
        }
    }
    int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //NW[i] = NW[i+1]*canDecode(i,1) + NW[i+2]*canDecode(i,2)
        if(s == "")
        {
            return 0;
        }
        int n = s.size();
        str = s;
        int * NW = new int[n];
        NW[n-1] = canDecode(n-1,1);
        if(n == 1)
        {
            return NW[n-1];
        }
        NW[n-2] = canDecode(n-2,2) + canDecode(n-2,1)*NW[n-1];
        int i;
        for(i = n-3; i >= 0; i--)
        {
            NW[i] = canDecode(i,2) * NW[i+2] + canDecode(i,1) * NW[i+1];
        }
        int result = NW[0];
        delete []NW;
        return result;
    }
};