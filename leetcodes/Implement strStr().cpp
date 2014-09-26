class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int countH = 0;
        while(haystack[countH] != '\0')
        {
            countH++;
        }
        int countN = 0;
        while(needle[countN] != '\0')
        {
            countN++;
        }
        if(countN == 0)
        {
            return haystack;
        }
        if(countH == 0 && countN != 0)
        {
            return NULL;
        }
        int * next = new int[countN]; 
        next[0] = -1;
        int j = -1;
        int i;
        for(i = 1; i < countN; i++)
        {
            while(j >= 0 && needle[j+1] != needle[i])
            {
                j = next[j];
            }
            if(needle[j+1] == needle[i])
            {
                j++;
            }
            next[i] = j;
        }
        j= -1;
        for(i = 0; i < countH; i++)
        {
            while(j >= 0 && needle[j+1] != haystack[i])
            {
                j = next[j];
            }
            if(needle[j+1] == haystack[i])
            {
                j++;
            }
            if(j == countN-1)
            {
                delete []next;
                return haystack+i-j;
            }
        }
        delete []next;
        return NULL;
        
    }
};