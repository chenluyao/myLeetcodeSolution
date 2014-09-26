class Solution {
public:
    vector<vector<int> > subCombinationSum(vector<int> &candidates, int pos,int target)//from pos to end
    {
        vector<vector<int> > result;
        vector<vector<int> > last;
        vector<int> line;
        int m = candidates.size();
        if(target == 0)//success
        {
            result.push_back(line);
            return result;
        }
        if(pos == m && target != 0)//fail
        {
            return result;
        }
        int count= 0;
        int digit = candidates[pos];
        while(count * digit <= target)
        {
            last = subCombinationSum(candidates,pos+1,target - count * digit);
            int i;
            for(i = 0; i < last.size(); i++)
            {
                line = last[i];
                line.insert(line.begin(),count,digit);
                result.push_back(line);
            }
            count++;
        }
        return result;
        
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        
        int m = candidates.size();
        if(m == 0)
        {
            return result;
        }
        sort(candidates.begin(),candidates.end());
        
        //vector<vectort<int> > * resultList = new vector<vectort<int> >[m+1];
        return subCombinationSum(candidates,0,target);
    }
};