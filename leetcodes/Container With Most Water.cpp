class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = height.size();
        if(m == 0)
        {
            return 0;
        }
        vector<int> leftBorder;
        vector<int> rightBorder;
        int i;
        int j;
        leftBorder.push_back(0);
        rightBorder.push_back(m-1);
        int index;
        for(i = 1; i < m; i++)
        {
            index = leftBorder[(int)leftBorder.size()-1];
            if(height[i] > height[index])
            {
                leftBorder.push_back(i);
            }
        }
        for(i = m-2; i >=0; i--)
        {
            index = rightBorder[(int)rightBorder.size()-1];
            if(height[i] > height[index])
            {
                rightBorder.push_back(i);
            }
        }
        int maxA = 0;
        int s1 = leftBorder.size();
        int s2 = rightBorder.size();
        for(i = 0; i < s1; i++)
            for(j = 0; j < s2; j++)
            {
                int iIn = leftBorder[i];
                int jIn = rightBorder[j];
                if(iIn < jIn)
                {
                    int h = height[iIn] < height[jIn]?height[iIn] :height[jIn];
                    int w = jIn - iIn;
                    int a = h*w;
                    if(a > maxA)
                    {
                        maxA = a;
                    }
                }
            }
        return maxA;
    }
};