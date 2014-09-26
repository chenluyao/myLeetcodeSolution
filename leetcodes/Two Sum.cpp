class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        int m = numbers.size();
        if(m == 0)
        {
            return result;
        }
        vector<int> copy(numbers);
        sort(copy.begin(),copy.end());
        int i = 0;
        int j = m-1;
        int sum;
        while(i < j)
        {
            
            sum = copy[i] + copy[j];
            if(sum < target )
            {
                i++;
            }
            else if(sum > target)
            {
                j--;
            }
            else
            {
                break;
            }
        }
        int num1 = copy[i];
        int num2 = copy[j];
        int index1 = -1;
        int index2 = -1;
        for(i = 0; i < m; i++)
        {
            if(numbers[i] == num1 && index1 == -1)
            {
                index1 = i;
            }
            if(numbers[i] == num2 && index2 == -1)
            {
                if(index1  == i)
                {
                    continue;
                }
                else
                {
                    index2 = i;
                }
            }
        }
        if(index1 > index2)
        {
            result.push_back(index2+1);
            result.push_back(index1+1);
        }
        else
        {
            result.push_back(index1+1);
            result.push_back(index2+1);
        }
        return result;
        
    }
};