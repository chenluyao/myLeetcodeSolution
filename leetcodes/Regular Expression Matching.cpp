class Solution {
public:
    
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if(*p == '\0')
        {
            return (*s == '\0');
        }
        
        if(*(p+1) == '*')
        {
            while(!isMatch(s,p+2))
            {
                if(*p == *s || *p == '.' && *s != '\0')
                {
                    s++;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            if(*p == *s || *p == '.' && *s != '\0')
            {
                return isMatch(s+1,p+1);
            }
            else
            {
                return false;
            }
        }
        
    }
};