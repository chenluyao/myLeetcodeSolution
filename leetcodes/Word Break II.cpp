class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> last;
        last.clear();
        int m = s.size();
        if(m == 0)
        {
            return last;
        }
        //assume no "" in dict
        int n = dict.size();
        if(n == 0)
        {
            return last;
        }
        int i;
        vector<string>* result = new vector<string>[m+1];
        bool * match = new bool[m+1];
        for(i = 0; i < m+1; i++)
        {
            match[i] = false;// can match from s[i]?
        }
        match[m] = true;//match to end
        result[m].clear();
        result[m].push_back("");
        int j;
        string sub;
        bool found;
        bool foundone;
        for(i = m-1; i>=0 ; i--)
        {
            found = false;
            foundone = false;
            for(j = i; j < m; j++)
            {
                sub = s.substr(i,j-i+1);
                if(dict.find(sub)!= dict.end())
                {
                    
                    found = match[j+1];
                    if(found == true)
                    {
                        last = result[j+1];
                        for(int k = 0; k < last.size(); k++)
                        {
                            string sl = last[k];
                            string tmp = sub;
                            if(sl != "")
                            {
                                tmp.append(" ");
                                tmp.append(sl);
                            }
                            result[i].push_back(tmp);
                        }
                        
                        //break;
                        foundone = true;
                    }
                }
            }
            match[i] = foundone;
        }
        
        vector<string> re(result[0].begin(),result[0].end());
        delete []result;
        delete []match;
        return re;
    }
};