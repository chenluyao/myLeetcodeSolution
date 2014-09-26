class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()<4)
        {   
            return vector<vector<int> >();
        }
        sort(num.begin(),num.end());
        set<vector<int> > four;
        vector<int> collect;
        int first,second,third,fourth;
        int firstNum,secondNum;
        int size = num.size();
        for(first = 0; first != size - 3; first++)
            for(second = first+1; second != size -2; second++)
            {
                firstNum = num.at(first);
                secondNum = num.at(second);
                
                third = second+1;
                fourth = size -1;
                
                while(third < fourth)
                {
                    if(num.at(third)+num.at(fourth)+firstNum+secondNum == target)
                    {
                        collect.clear();
                        collect.push_back(firstNum);
                        collect.push_back(secondNum);
                        collect.push_back(num.at(third));
                        collect.push_back(num.at(fourth));
                        four.insert(collect);
                        third++;
                        fourth--;
                    }
                    else if(num.at(third)+num.at(fourth)+firstNum+secondNum < target)
                    {
                        third ++;
                    }
                    else
                    {
                        fourth --;
                    }
                    
                }
            }
        return vector<vector<int> >(four.begin(),four.end());
    }
};