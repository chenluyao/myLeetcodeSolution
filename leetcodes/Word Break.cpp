class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = s.size();
        if(m == 0)
        {
            return false;
        }
        //how to deal with "" and ["",XXXX]?
        //assume no "" in dict
        
        int i;
        int j;
        bool * result = new bool [m];
        for(i = 0 ;i < m; i++)
        {
            result[i] = false;
        }
        for(i = m-1; i >=0; --i)
        {
            for(j = i; j < m; ++j)
            {
                string temp = s.substr(i,j-i+1);
                if(dict.find(temp) != dict.end() && (j == m-1 || result[j+1] == true))
                {
                    result[i] = true;
                    break;
                }
            }
        }
        bool r = result[0];
        delete []result;
        return r;
    }
};