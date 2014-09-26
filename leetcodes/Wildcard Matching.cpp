class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const char * str;
        const char * ptr;
        
        bool star = false;
        for(str = s, ptr = p;*str != '\0' ; )
        {
            if(*ptr == '?' || *ptr == *str)
            {
                ptr++;
                str++;
            }
            else if(*ptr == '*')
            {
                star = true;
                while(*ptr == '*')
                {
                    ptr++;
                }
                if(*ptr == '\0')
                {
                    return true;//!!!!!
                }
                s = str;//!!!!
                p = ptr;//!!!!
            }
            else if(*ptr != *str )//*ptr == '\0' also in this catogory
            {
                if(star == false)
                {
                    return false;
                }
                else
                {
                    s++;
                    str = s;
                    ptr = p;
                }
            }
            
        }
        while(*ptr == '*')
        {
            ptr++;
        }
        return *ptr == '\0';
        
    }
};