class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = height.size();
        if(m == 0)
        {
            return 0;
        }
        stack<int> stk;
        //stk.clear();
        int i;
        //stk.push(0);
        int maxA = 0;
        int area;
        int hi,ri,li;
        for(i = 0; i < m; i++)
        {
            if(stk.empty() || height[i] >= height[stk.top()])//stk.empty()always should be there. not only for index 0,but for pop up
            {
                
            }
            else
            {
                while(!stk.empty() && height[stk.top()] >= height[i])
                {
                    hi = stk.top();
                    stk.pop();
                    if(stk.empty())
                    {
                        li = 0;
                    }
                    else
                    {
                        li = stk.top()+1;
                    }
                    ri = i-1;
                    area = height[hi] * (ri-li+1);
                    if(area > maxA)
                    {
                        maxA = area;
                    }
                }
                
            }
            stk.push(i);//
        }
        while(!stk.empty())
        {
            hi = stk.top();
            stk.pop();
            if(stk.empty())
            {
                li = 0;
            }
            else
            {
                li = stk.top()+1;
            }
            ri = i-1;
            area = height[hi] * (ri-li+1);
            if(area > maxA)
            {
                maxA = area;
            }
        }
        return maxA;
        
    }
};