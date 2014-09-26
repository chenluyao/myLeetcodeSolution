class Solution {
public:
    vector<string> digit2string(char d)
    {
        vector<string> re;
        re.clear();
        switch(d)
        {
            case '2': re.push_back("a");re.push_back("b");re.push_back("c");break;
            case '3': re.push_back("d");re.push_back("e");re.push_back("f");break;
            case '4': re.push_back("g");re.push_back("h");re.push_back("i");break;
            case '5': re.push_back("j");re.push_back("k");re.push_back("l");break;
            case '6': re.push_back("m");re.push_back("n");re.push_back("o");break;
            case '7': re.push_back("p");re.push_back("q");re.push_back("r");re.push_back("s");break;
            case '8': re.push_back("t");re.push_back("u");re.push_back("v");break;
            case '9': re.push_back("w");re.push_back("x");re.push_back("y");re.push_back("z");break;
            case '0': re.push_back(" ");break;
            default: break;
        }
        return re;
    }
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        int m = digits.size();
        if(m == 0)
        {
            result.push_back("");
            return result;
        }
        int i;
        vector<string> last = digit2string(digits[m-1]);
        vector<string> now;
        int j;
        int k;
        for(i = m-2; i >=0; i--)
        {
            result.clear();
            now = digit2string(digits[i]);
            int lastS = last.size();
            int nowS = now.size();
            for(j = 0; j < nowS; j++)
                for(k = 0; k < lastS; k++)
                {
                    string s = now[j];
                    string t = last[k];
                    result.push_back(s.append(t));
                }
            last = result;    
        }
        return last;
        
    }
};