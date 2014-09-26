class Solution {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0;
        int m = s.size();
        if(m == 0)
        {
            return 0;
        }
        int i;
        for(i = 0; i < m; i++)
        {
            switch(s[i])
            {
                case 'M': result += 1000; break;
                case 'D': result += 500; break;
                case 'L': result += 50; break;
                case 'V': result += 5; break;
                case 'C': if(i+1 < m && (s[i+1] == 'D' || s[i+1] == 'M'))
                {
                    result -= 100; 
                }
                else
                {
                    result += 100;
                }
                break;
                case 'X': if(i+1 < m && (s[i+1] == 'L' ||s[i+1] == 'C'))
                {
                    result -= 10; 
                }
                else
                {
                    result += 10;
                }
                break;
                case 'I': if(i+1 < m && (s[i+1] == 'V' || s[i+1] == 'X'))
                {
                    result -= 1; 
                }
                else
                {
                    result += 1;
                }
                break;
            }
        }
        return result;
    }
};