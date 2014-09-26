class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        result.push_back(0);
        
        int i;
        int j;
        for(i = 0; i < n; i++)
        {
            int high = 1<<i;
            for(j = result.size()-1; j >=0; j--)
            {
                result.push_back(high+result[j]);
            }
        }
        return result;
    }
};