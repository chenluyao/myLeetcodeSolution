class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> vs;
        if(n == 0)
        {
            return vs;
        }
        vector<string> last1;
        vector<string> last2;
        vector<string> * result = new vector<string>[n+1];
        
        result[1].push_back("()");
        int i;
        int j;
        int k;
        string s;
        vector<string> re;
        for(i = 2; i <= n; i++)
        {
            re.clear();
            last1 = result[i-1];
            for(k = 0; k < last1.size(); k++)
            {
                s = last1[k];
                re.push_back("("+s+")");
            }
            for(j = 1; j <= i-1; j++)
            {
                k = i-j;
                last1 = result[j];
                last2 = result[k];
                int iter1;
                int iter2;
                for(iter1 = 0; iter1 < last1.size(); iter1++)
                    for(iter2 = 0; iter2 < last2.size(); iter2++)
                    {
                        string s1 = last1[iter1];
                        string s2 = last2[iter2];
                        s1.append(s2);
                        re.push_back(s1);
                    }
            }
            set<string> setS(re.begin(),re.end());
            vector<string> re2(setS.begin(),setS.end());
            result[i] = re2;
        }
        vector<string> re3 = result[n];
        delete []result;
        return re3;
    }
};