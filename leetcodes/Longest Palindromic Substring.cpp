class Solution {
public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        if(n < 2)
        {
            return s;
        }
        int i;
        vector<int> resultOdd;
        vector<int> resultEven;
        int len = 1;
        bool canExpand;
        int resultIndex;
        bool isOdd;
        for(i = 0; i < n; i++)
        {
            resultOdd.push_back(1);//result[i] = length of substring with center of s[i]:s[i-result[i]+1]~s[i+result[i]-1]
            //n >= 2 so can't be only one,can't be final result
        }
        for(i = 0; i < n; i++)
        {
            if(i+1 < n && s[i] == s[i+1])
            {
                resultEven.push_back(1);//s[i-result[i]+1]~s[i+result[i]]
                resultIndex = i;//initialize if only one, don't entry while
                isOdd = false;//initialize if only one, don't entry while
            }
            else
            {
                resultEven.push_back(0);
            }
        }
        while(true)
        {
            len ++;
            canExpand = false;
            for(i = 0; i < resultOdd.size(); i++)
            {
                if(resultOdd[i] == len - 1)//don't expand the short, only expand the one keep expanding
                {
                    int left  = i - len + 1;
                    int right = i + len - 1;
                    if(left >= 0 && right <= n-1 && s[left] == s[right])
                    {
                        canExpand = true;
                        isOdd = true;
                        resultOdd[i]++; // result[i] = len;
                        resultIndex = i;//last round may only set unique resultIndex once.
                    }
                }
                
            }
            for(i = 0; i < resultEven.size(); i ++)
            {
                if(resultEven[i] == len - 1)
                {
                    int left  = i - len + 1;
                    int right = i + len;
                    if(left >= 0 && right <= n-1 && s[left] == s[right])
                    {
                        canExpand = true;
                        isOdd = false;
                        resultEven[i]++; // result[i] = len;
                        resultIndex = i;//last round may only set unique resultIndex once.
                    }
                }
            }
            if(canExpand == false)
            {
                break;
            }
        }
        string re;
        if(isOdd == true)
        {
            re = s.substr(resultIndex-resultOdd[resultIndex]+1, 2*resultOdd[resultIndex]-1);
        }
        else
        {
            re = s.substr(resultIndex-resultEven[resultIndex]+1, 2*resultEven[resultIndex]);
        }
        return re;
        
    }
};