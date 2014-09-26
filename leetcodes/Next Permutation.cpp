class Solution {
public:
    int findMinBigger(vector<int> &num, int in, int t)
    {
        int i;
        int result = in;
        bool find;
        for(i = in; i < num.size(); i++)
        {
            if(num[i] > t)
            {
                if(find && num[i] < num[result])
                {
                    result = i;
                }
                else if(!find)
                {
                    result = i;
                }
            }
        }
        return result;
    }
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       int n = num.size();
       if(n < 2){}
       int i;
       bool findDec = false;
       
       for(i = n - 2; i >= 0; i--)
       {
           if(num[i] >= num[i+1])
           {}
           else
           {
               findDec = true;
               break;
           }
       }
       if(findDec)
       {
           int index = findMinBigger(num,i+1,num[i]);
           int temp = num[index];
           num[index] = num[i];
           num[i] = temp;
           sort(num.begin()+i+1,num.end());
       }
       else
       {
           sort(num.begin(),num.end());
       }
       
    }
};