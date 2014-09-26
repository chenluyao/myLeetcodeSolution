class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<int> leftIndex;
        map<int,int> right2Left;
       
        int m = s.size();
        int i;
        int len = 0;
        for(i = 0; i < m; i++)
        {
            if(s[i] == '(')
            {
                leftIndex.push(i);
            }
            else
            {
                if(!leftIndex.empty())
                {
                    int l = leftIndex.top();
                    leftIndex.pop();
                    if(l-1 >=0 && right2Left.find(l-1) != right2Left.end())
                    {
                        l = right2Left[l-1];
                    }
                    right2Left[i] = l;
                    if(i-l+1 > len)
                    {
                        len = i-l+1;
                    }
                }
            }
        }
        return len;
    }
};