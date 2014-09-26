class Solution {
public:
    int nextBig(vector<int> &temp, int i, int target)
    {
        int min = i;
        int j;
        for(j = i ; j < temp.size(); j++)
        {
            if(temp[j] > target)
            {
                if(temp[j] < temp[min])
                {
                    min = j;
                }
            }
        }
        return min;
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        if(num.size() == 0)
        {
            return result;
        }
        sort(num.begin(),num.end());
        result.push_back(num);
        if(num.size() == 1)
        {
            return result;
        }
        int i;
        vector<int> temp = num;
        while(true)
        {
            for(i = temp.size()-2; i >= 0; i--)
            {
                if(temp[i] < temp[i+1])
                {
                    int index = nextBig(temp,i+1,temp[i]);
                    int v = temp[index];
                    temp[index] = temp[i];
                    temp[i] = v;
                    sort(temp.begin()+i+1,temp.end());
                    result.push_back(temp);
                    break;
                }
            }
            if(i < 0)//finish
            {
                break;
            }
        }
        return result;
        
    }
};