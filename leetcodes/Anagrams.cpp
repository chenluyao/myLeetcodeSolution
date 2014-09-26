class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> result;
        int m = strs.size();
        map<string,vector<string> > mapS;
        map<string,vector<string> >::iterator iter;
        int i;
        for(i = 0; i < m; ++i )
        {
            string s = strs[i];
            string k = s;
            sort(k.begin(),k.end());
            mapS[k].push_back(s);
        }
        for(iter = mapS.begin(); iter != mapS.end(); iter++)
        {
            if((iter->second).size() > 1)
            {
                for(i = 0; i < (iter->second).size(); ++i)
                {
                    result.push_back((iter->second)[i]);
                }
            }
        }
        return result;
    }
};