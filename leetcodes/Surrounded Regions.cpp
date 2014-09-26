class Solution {
public:
    
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int m = board.size();
        if(m == 0)
        {
            return;
        }
        int n = board[0].size();
        if(n == 0)
        {
            return;
        }
        int deltaX[4] = {-1,0,1,0};
        int deltaY[4] = {0,-1,0,1};
        queue<int> posX;
        queue<int> posY;
        int i;
        int j;
        for(i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
            {
                posX.push(i);
                posY.push(0);
            }
            if(board[i][n-1] == 'O')
            {
                posX.push(i);
                posY.push(n-1);
            }
        }
        for(j = 1; j < n-1; j++)
        {
            if(board[0][j] == 'O')
            {
                posX.push(0);
                posY.push(j);
            }
            if(board[m-1][j] == 'O')
            {
                posX.push(m-1);
                posY.push(j);
            }
        }
        int ii,jj;
        int k;
        while(!posX.empty())
        {
            ii = posX.front();
            jj = posY.front();
            posX.pop();
            posY.pop();
            board[ii][jj] = '@';
            for(k = 0; k < 4; k++)
            {
                int newX = ii+deltaX[k];
                int newY = jj+deltaY[k];
                if(newX < m && newX >= 0 && newY < n && newY >= 0)
                {
                    if(board[newX][newY] == 'O')
                    {
                        posX.push(newX);
                        posY.push(newY);
                    }
                }
            }
        }
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
            {
                if(board[i][j] == '@')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
            
        
    }
};