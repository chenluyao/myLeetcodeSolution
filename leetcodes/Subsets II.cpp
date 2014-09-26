class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //non-descending order!
        vector<vector<int> > r;
        sort(S.begin(),S.end());
        int m = S.size();
        int i;
        int j;
        vector<int> emp;
        vector<int> line;
        r.push_back(emp);
        for(i = 0; i < m; ++i)
        {
            for(j = (int)r.size()-1; j >= 0; --j)//if not reverse, you have to save r.size() first, in case it change
            {
                line = r[j];
                line.push_back(S[i]);
                r.push_back(line);
            }
        }
        set<vector<int> > setR(r.begin(),r.end());
        vector<vector<int> > result(setR.begin(),setR.end());
        return result;
    }
};