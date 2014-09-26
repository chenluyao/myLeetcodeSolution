class Solution {
public:
    
     
    bool * row;
    bool * col;
    bool * line13;//i+j
    bool * line24;//
    vector<vector<string> > result;
    int * queen;
    int sum;
    void tryplace(int i, int n)
    {
        if(i >= n)
        {
            sum++;
        }
        else
        {
            int j;
            for(j = 0; j < n; j++)
            {
                
                if(!col[j] && !line13[i+j] && !line24[n-1-i+j] )
                {
                    queen[i] = j;
                    col[j]=true;
                    line13[i+j] = true;
                    line24[n-1-i+j] = true;
                    tryplace(i+1,n);
                    col[j]=false;
                    line13[i+j] = false;
                    line24[n-1-i+j] = false;
                }
                
                
            }
            
        }
    }
    
 int totalNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(n == 0)
        {
            return 0;
        }
        row = new bool[n];
        col = new bool[n];
        line13 = new bool[2*n-1];//i+j
        line24 = new bool[2*n-1];//n-1-i+j
        
        int i;
        int j;
        for(i = 0; i < n; i++)
        {
            row[i] = false;
            col[i] = false;
            line13[i] = false;
            line24[i] = false;
        }
        for(i = n; i < 2*n -1; i++ )
        {
            line13[i] = false;
            line24[i] = false;
        }
        queen = new int[n];
        sum = 0;
        tryplace(0,n);
        
        return sum;
            
    }
};