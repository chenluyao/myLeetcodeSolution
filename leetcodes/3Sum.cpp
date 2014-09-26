class Solution {
public:
   
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //sort the vector
        if(num.size()<3)
        {
            return vector<vector<int> >();
        }
        sort(num.begin(),num.end());
        set<vector<int> > threeSumCollection;
        vector<int>::iterator iter;
        vector<int>::iterator twoSumStart;
        vector<int>::iterator twoSumEnd;
        vector<int> triple;
        for(iter = num.begin();iter != num.end()-2; ++iter)
        {
            int fixedNum = (*iter);
            //num.erase(iter);
            twoSumStart = iter+1;
            twoSumEnd = num.end()-1;
            while(twoSumStart < twoSumEnd)
            {
                if((*twoSumStart) + (*twoSumEnd) == 0-fixedNum)
                {
                    triple.push_back(fixedNum);
                    triple.push_back(*twoSumStart);
                    triple.push_back(*twoSumEnd);
                    threeSumCollection.insert(triple);
                    twoSumStart++;
                    twoSumEnd --;
                }
                else if((*twoSumStart) + (*twoSumEnd) < 0-fixedNum)
                {
                    twoSumStart++;
                }
                else
                {
                     twoSumEnd --;
                }
                triple.clear();
            }
        }
        return vector<vector<int> >(threeSumCollection.begin(), threeSumCollection.end());
        
    }
};