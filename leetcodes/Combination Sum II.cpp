class Solution {
public:
    vector<vector<int> > subSum(vector<int> &num, int target, int start)
    {
        int m = num.size();
        int i;
        int j;
        vector<vector<int> > result;
        vector<int> line;
        vector<vector<int> > result1;
        vector<vector<int> > result2;
        
        if(start >= m || target <= 0|| num[start] > target)
        {
            result.clear();
            return result;
        }
        else if(num[start] == target)
        {
            line.clear();
            line.push_back(num[start]);
            result.push_back(line);
            return result;
        }
        else
        {
            result1 = subSum(num,target,start+1);
            result2 = subSum(num,target-num[start],start+1);
            for(i = 0; i < result1.size(); ++i)
            {
                result.push_back(result1[i]);
            }
            for(i = 0; i < result2.size(); ++i)
            {
                //line.clear();
                line = result2[i];
                line.insert(line.begin(),1, num[start]);
                //line.push_back(num[start]);
                //for(j = 0; j < result2[i].size(); ++j)
                //{
                  //  line.push_back(result2[i][j]);
                //}
                result.push_back(line);
            }
            set<vector<int> > setR(result.begin(),result.end());
            vector<vector<int> > r(setR.begin(),setR.end());
            return r;
        }
        
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(),num.end());
        return subSum(num,target,0);
        
    }
};