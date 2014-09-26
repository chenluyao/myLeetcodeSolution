class Solution {
public:
    int ABS(int x)
    {
        return x>0?x:(0-x);
    }
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int output;
        bool setOut = false;
        sort(num.begin(),num.end());
        vector<int>::iterator iter;
        vector<int>::iterator start;
        vector<int>::iterator end;
        for(iter = num.begin(); iter!= num.end()-2; iter++)
        {
            int fixedNum = *iter;
            start = iter+1;
            end = num.end()-1;
            while(start<end)
            {
                int sum = *start + *end + fixedNum;
                if(sum == target)
                {
                    setOut = true;
                    output = target;
                    break;
                }
                else if(sum < target)
                {
                    
                    if(setOut == false)
                    {
                        setOut = true;
                        output = sum;
                    }
                    else if(ABS(sum-target)<ABS(output-target))
                    {
                        output = sum;
                    }
                    start++;
                }
                else
                {
                   
                    if(setOut == false)
                    {
                        setOut = true;
                        output = sum;
                    }
                    else if(ABS(sum-target)<ABS(output-target))
                    {
                        output = sum;
                    }
                    end--;
                }
            }
        }
        return output;
    }
};