class Solution {
public:
    
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j;
        bool exist[9];
        //test row
        for(i=0;i<9;i++)
        {
            memset(exist,0,sizeof(bool)*9);
            for(j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(exist[board[i][j]-'1']==false)
                    {
                        exist[board[i][j]-'1']=true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        //test colomn
        for(j=0;j<9;j++)
        {
            memset(exist,0,sizeof(bool)*9);
            for(i=0;i<9;i++)
            {
                if(board[i][j]!='.')
                {
                    if(exist[board[i][j]-'1']==false)
                    {
                        exist[board[i][j]-'1']=true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
         //test 3*3
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {   
                memset(exist,0,sizeof(bool)*9);
                int ii,jj;
                for(ii = 3*i; ii<3*i+3;ii++)
                    for(jj = 3*j;jj<3*j+3;jj++)
                    {
                        if(board[ii][jj]!='.')
                        {
                            if(exist[board[ii][jj]-'1']==false)
                            {
                                exist[board[ii][jj]-'1']=true;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
            }
        }
        return true;
    }
};