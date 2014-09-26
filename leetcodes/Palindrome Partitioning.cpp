class Solution {
public:
    vector<vector<string> > partition(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<string> > r;
        if(s == "")
        {
            return r;
        }
        int i;
        int j;
        int k;
        int m = s.size();
        vector<vector<string> > * result = new vector<vector<string> >[m];
        bool **palin = new bool* [m];
        for(i = 0; i < m; ++i)
        {
            palin[i] = new bool[m];
        }
        for(i = 0; i < m; ++i)
            for(j = 0; j < m; ++j)
            {
                palin[i][j] = false;
            }
        
        vector<string> line;
        line.push_back(s.substr(m-1,1));
        result[m-1].push_back(line);
        
        for(i = m-2; i>=0; --i )
        {
            for(j = i; j <= m-1; ++j)
            {
                //palin[i,j]
                if(s[j] == s[i] && (j-i < 2 || palin[i+1][j-1] == true))
                {
                    palin[i][j] = true;
                }
                if(palin[i][j])
                {
                    string pal = s.substr(i,j-i+1);
                    line.clear();
                    if(j == m-1)
                    {
                        line.push_back(pal);
                        result[i].push_back(line);
                    }
                    else
                    {
                        r = result[j+1];
                        for(k = 0; k < result[j+1].size(); ++k)
                        {
                            line = result[j+1][k];
                            line.insert(line.begin(),pal);
                            result[i].push_back(line);
                        }
                    }
                }
            }
        }
        r = result[0];
        
        for(i = 0; i < m; ++i)
        {
            delete []palin[i];
        }
        delete []palin;
        delete []result;
        return r;
    }
};