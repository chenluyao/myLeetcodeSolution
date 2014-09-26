class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = prices.size();
        if(m < 2)
        {
            return 0;
        }
        int i;
        int sum = 0;
        int buy = -1;
        int sell = -1;
        for(i = 0; i < m ; )
        {
            while(i != m-1 && prices[i+1] < prices[i])
            {
                ++i;
            }
            if(i == m-1)
            {
                break;//continus going down till end
            }
            else
            {
                buy = i;
            }
            ++i;
            while(i != m-1 && prices[i+1] >= prices[i])
            {
                ++i;
            }
            sell = i;
            if(buy != -1 && sell != -1)
            {
                sum += prices[sell] - prices[buy];
            }
        }
        return sum;
    }
};