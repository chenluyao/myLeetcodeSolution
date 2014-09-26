class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        vector<vector<int> > sub;
        vector<int > line;
        int i;
        result.clear();
        sub.clear();
        line.clear();
        if(n  < k || k == 0)
        {
            result.push_back(line);//IMPORTANT
            return result;
        }
        if(n == k)
        {
            for(i = 1; i <= n; i++)
            {
                line.push_back(i);
            }
            result.push_back(line);
            return result;
        }
        if(k == 1)
        {
            for(i = 1; i <= n; i++)
            {
                line.clear();//!!!!!!
                line.push_back(i);
                result.push_back(line);
            }
            return result;
        }
        
        
        sub = combine(n-1,k);
        int size = sub.size();
        for(i = 0; i< size; i++)
        {
            result.push_back(sub[i]);
        }
        sub.clear();
        sub = combine(n-1,k-1);
        size = sub.size();
        for(i = 0; i< size; i++)
        {
            line = sub[i];
            line.push_back(n);
            result.push_back(line);
            
        }
        return result;
    }
};