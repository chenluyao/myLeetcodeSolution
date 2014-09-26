class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i;
        int j;
        bool ** row = new bool * [9];
        bool ** col = new bool * [9];
        bool ** grid = new bool * [9];
        for(i = 0; i < 9; i++)
        {
            row[i] = new bool[10];
            col[i] = new bool[10];
            grid[i] = new bool[10];
        }
        for(i = 0; i < 9; i++)
            for(j = 0; j < 10; j++)
            {
                row[i][j] = false;
                col[i][j] = false;
                grid[i][j] = false;
            }
        vector<vector<int> > undecidedNodes;
        
        for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if(c <= '9' && c >= '1')
                {
                    row[i][c-'0'] = true;
                    col[j][c-'0'] = true;
                    int i1 = i/3;
                    int j1 = j/3;
                    grid[i1*3+j1][c-'0'] = true; 
                }
                else
                {
                    vector<int> line;
                    line.push_back(i);
                    line.push_back(j);
                    undecidedNodes.push_back(line);
                }
            }
        int k = 0;
        int m = undecidedNodes.size();
        
        int nodeR;
        int nodeC;
        int d;
        vector<int> tryNum;
        while(k < m)
        {
            nodeR = undecidedNodes[k][0];
            nodeC = undecidedNodes[k][1];
            if(tryNum.size() == k)
            {
                tryNum.push_back(0);
            }
            d = tryNum[k];
            bool find = false;
            while(d != 9)
            {
                d ++;
                int ii = nodeR/3;
                int jj = nodeC/3;
                if(!row[nodeR][d] && !col[nodeC][d] && !grid[(nodeR/3) * 3+(nodeC/3)][d])
                {
                    row[nodeR][d]  = true;
                    col[nodeC][d] = true;
                    
                    grid[(nodeR/3) * 3+(nodeC/3)][d] = true;
                    //board[nodeR][nodeC] = d+'0';
                    find = true;
                    break;
                }
            }
            if(find == true)
            {
                tryNum[k]= d;
                k++;
            }
            else
            {   
                tryNum[k] = 0;
                k--;
                d = tryNum[k];
                
                nodeR = undecidedNodes[k][0];
                nodeC = undecidedNodes[k][1];
                row[nodeR][d]  = false;
                col[nodeC][d] = false;
                int ii = nodeR/3;
                int jj = nodeC/3;
                grid[(nodeR/3) * 3+(nodeC/3)][d] = false;
            }
            
            
        }
        for(i = 0; i < tryNum.size(); i++)
        {
            board[undecidedNodes[i][0]][undecidedNodes[i][1]] = tryNum[i]+'0';
        }
        
        
        
        
    }
};