class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //non-descending order!
        sort(S.begin(),S.end());
        vector<vector<int> > sub;
        vector<int> d;
        int n = S.size();
        sub.push_back(d);
        if(n == 0)
        {
            return sub;
        }
        int i;
        int j;
        
        for(i = 0; i < n; i++)
        {
            for(j = sub.size()-1; j>=0 ;j--)
            {
                d = sub[j];
                d.push_back(S[i]);
                sub.push_back(d);
            }
        }
        return sub;
    }
};