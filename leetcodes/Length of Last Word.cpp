class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //"hello world   "
        //"   "
        //""
        //count the len of each word? don't sound like a good idea
        //start from end!
        int len = 0;
        
        if(*s == '\0')
        {
            return 0;
        }
        const char * p = s;
        while(*p != '\0')
        {
            ++p;
        }
        --p;
        while(p >= s && *p == ' ')
        {
            --p;
        }
        while(p >= s && *p != ' ')
        {
            ++len;
            --p;
        }
        return len;
    }
};