class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i;
        int size = prices.size();
        if(size < 2)
            return 0;
        int max = prices[size-1];
        int maxProfit = 0;
        for(i = size -2; i >=0; i--)
        {
            if(max < prices[i+1])
            {
                max = prices[i+1];
            }
            if(maxProfit < max - prices[i])
            {
                maxProfit = max - prices[i];
            }
        }
        return maxProfit;
    }
};