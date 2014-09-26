class Solution {
public:
    char turnLower(char x)
    {
        if(x <= 'Z' && x >= 'A')
        {
            return x-'A'+'a';
        }
        return x;
    }
    bool isAlphanumeric(char x)
    {
        return (x <= 'Z' && x >= 'A' || x <='z' && x >= 'a'|| x <= '9' && x >= '0');
    }
    bool isPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = s.size();
        if(m == 0)
        {
            return true;
        }
        int i = 0;
        int j = m-1;
        while(i <= j)
        {
            while(!isAlphanumeric(s[i]) && i <= m-1)
            {
                ++i;
            }
            while(!isAlphanumeric(s[j]) && j >= 0)
            {
                --j;
            }
            if(i <= m-1 && j >= 0 && i <= j)
            {
                if(turnLower(s[i]) != turnLower(s[j]))
                {
                    return false;
                }
                else
                {
                    ++i;
                    --j;
                }
            }
        }
        return true;
    }
};