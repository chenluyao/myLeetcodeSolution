class Solution {
public:
    bool isDigit(char c)
    {
        if(c <= '9' && c >= '0')
        {
            return true;
        }
        return false;
    }
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxInt = 0x7fffffff;
        int minInt = 0x80000000;
        int r  = 0;
        bool digitStart = false;
        bool sign = false;
        //bool whitespace = false;
        bool positive = true;
        while(*str != '\0')
        {
            while(*str == ' ')
            {
                str++;
            }
            if((*str == '-' || *str == '+') && isDigit(*(str+1)))
            {
                if(*str == '-')
                {
                    positive = false;
                }
            }
            else if(isDigit(*str))
            {
                digitStart = true;
                while(isDigit(*str))
                {
                    int d = *str - '0';
                    if(maxInt/10 < r)
                    {
                        return positive ? maxInt:minInt;
                    }
                    else
                    {
                        r *= 10;
                        if(maxInt - d < r)
                        {
                            return positive ? maxInt:minInt;
                        }
                        else
                        {
                            r += d;
                        }
                    }
                    str++;
                }
                return positive ? r:0-r;
            }
            else
            {
                return 0;
            }
            str++;
        }
        return 0;
    }
};