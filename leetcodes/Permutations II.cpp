class Solution {

 public:
    int nextBig(vector<int> & num, int start, int target)
    {
        int resultIndex = start;
        int end = (int)num.size() - 1;
        for(int j = start+1; j <= end; j++)
        {
            if(num[j] < num[resultIndex] && num[j] > num[target])
            {
                resultIndex = j;
            }
        }
        return resultIndex;
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        sort(num.begin(),num.end());
        int m = num.size();
        if(m == 0)
        {
            return result;
        }
        result.push_back(num);
        if(m == 1)
        {
            return result;
        }
        vector<int> last;
        int i;
        last = result[0];
        while(true)
        {
            bool find = false;
            for(i = (int)last.size() -2 ; i >=0; i--)
            {
                if(last[i] < last[i+1])
                {
                    int exchangeIndex = nextBig(last,i+1,i);
                    int temp = last[exchangeIndex];
                    last[exchangeIndex] = last[i];
                    last[i] = temp;
                    sort(last.begin()+i+1,last.end());
                    find = true;
                    break;
                }
            }
            if(find == false)
            {
                break;
            }
            result.push_back(last);
        }
        return result;
    }
};