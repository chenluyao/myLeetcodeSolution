class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int m = matrix.size();
        if(m == 0)
        {
            return 0;
        }
        
        int n = matrix[0].size();
        if(n == 0)
        {
            return 0;
        }
        
        int ** height = new int*[m];
        int i;
        int j;
        for(i = 0; i < m; i++)
        {
            height[i] = new int[n];
        }
        
        //set up height[][]
        for(i = 0; i<m; i++)
        {
            for(j = 0; j < n ; j++)
            {
                if(i == 0)
                {
                    height[i][j] = matrix[i][j]-'0';
                }
                else
                {
                    if(matrix[i][j] != '0')
                    {
                        height[i][j] = height[i-1][j] +1;
                    }
                    else
                    {
                        height[i][j] = 0;
                    }
                }
            }
        }
        
        
        //
        int area;
        int maxA = 0;
        stack<int> h;
        for(i = 0; i < m; i++)
        {
            //h.clear();
            for(j = 0; j < n; j++)
            {
                if(h.empty() || height[i][h.top()] <= height[i][j])
                {
                    
                }
                else
                {
                    while(!h.empty() && height[i][h.top()] >= height[i][j])
                    {
                        int heightIndex = h.top();
                        h.pop();
                        int leftIndex;
                        if(h.empty())
                        {
                            leftIndex = 0;
                        }
                        else
                        {
                            leftIndex = h.top()+1;
                        }
                        area = height[i][heightIndex] * (j-leftIndex);
                        if(area > maxA)
                        {
                            maxA = area;
                        }
                    }
                }
                h.push(j);
            }
            while(!h.empty())
            {
                int heightIndex = h.top();
                h.pop();
                int leftIndex;
                if(h.empty())
                {
                    leftIndex = 0;
                }
                else
                {
                    leftIndex = h.top()+1;
                }
                area = height[i][heightIndex] * (j-leftIndex);
                if(area > maxA)
                {
                    maxA = area;
                }
            }
            
        }
        return maxA;
        
        
    }
};