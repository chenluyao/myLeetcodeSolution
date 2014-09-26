class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> save;
        
        int n = triangle.size();
        int i;
        int j;
        if(n == 1)
        {
            return triangle[0][0];
        }
        save.push_back(triangle[0][0]);
        
        for(i = 1; i < n; i++)
        {
            int d1 = save[0];
            save[0] = save[0]+triangle[i][0];
            int d2;
            for(j = 1; j < i; j++)//len = i+1
            {
                d2 = d1+triangle[i][j];//d1 = save[j -1]
                if(save[j]+triangle[i][j] < d2)
                {
                    d2 = save[j]+triangle[i][j];
                }
                d1 = save[j];
                save[j] = d2;
            }
            save.push_back(d1+triangle[i][i]);
        }
        int minN = save[0];
        for(i = 1; i < save.size(); i++)
        {
            if(save[i] < minN)
            {
                minN = save[i];
            }
        }
        return minN;
    }
};