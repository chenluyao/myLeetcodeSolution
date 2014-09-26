class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        if(numRows == 0)
        {
            return result;
        }
        vector<int> temp;
        temp.push_back(1);
        result.push_back(temp);
        while(numRows > 1 )
        {
            int cal;
            int cur = 0;
            int i;
            for(i = 0; i< temp.size(); i++)
            {
                cal = cur + temp[i];
                cur = temp[i];
                temp[i] = cal;
            }
            temp.push_back(cur);
            result.push_back(temp);
            
            numRows --;
        }
        return result;
    }
};