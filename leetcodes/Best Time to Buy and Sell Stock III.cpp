class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        if(size < 2)
        {
            return 0;
        }
        //sold at time i
        int maxprofit=0;
        vector<int> maxProfit;
        maxProfit.push_back(0);//sold at time 0, invalid
        int i;
        int j;
        int min = prices[0];
        for(i = 1;i <=size-1;i++ )
        {
            if(prices[i-1] < min)
            {
                min = prices[i-1];
            }
            maxProfit.push_back(prices[i]-min);
        }
        //
        int secondMax = prices[size-1];
        int secondMaxProfit = 0;
        for(i = size-2; i>=0;i--)
        {
            if(prices[i+1] > secondMax)
            {
                secondMax = prices[i+1];
            }
            if(secondMax - prices[i] > secondMaxProfit)
            {
                secondMaxProfit = secondMax - prices[i];
            }
            maxProfit[i]+= secondMaxProfit;
            if(maxProfit[i]>maxprofit)
            {
                maxprofit = maxProfit[i];
            }
            
        }
        return maxprofit;
        
    }
};