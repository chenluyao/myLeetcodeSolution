class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       int m = gas.size();
       if(m == 0)
       {
           return -1;//?
       }
       vector<int> profit;
       int i;
       for(i = 0; i < m; ++i)
       {
           profit.push_back(gas[i]-cost[i]);
       }
       int sum = 0;
       int min = 0x7fffffff;
       int index = -1;
       for(i = 0; i < m; ++i)
       {
           sum += profit[i];
           if(sum < min)
           {
               min = sum;
               index = i;
           }
       }
       if(sum < 0)
       {
           return -1;
       }
       else
       {
           return (index+1)%m;
       }
    }
};