class Solution {
public:
    int m;
    int n;
    int wordLen;
    bool **visited;
    bool subExist(vector<vector<char> > &board, int i, int j, string word, int wordPos)
    {
        if(wordPos == wordLen)
        {
            return true;
        }
        if(!(i >=0 && i < m && j >=0 && j < n && !visited[i][j]))
        {
            return false;
        }
        bool result = false;
        if(board[i][j] == word[wordPos] && !visited[i][j])
        {
            visited[i][j] = true;
            result =  subExist(board,i-1,j,word,wordPos+1)||subExist(board,i+1,j,word,wordPos+1)||subExist(board,i,j-1,word,wordPos+1)||subExist(board,i,j+1,word,wordPos+1);
            visited[i][j] = false;
        }
        return result;
        
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(word == "")
        {
            return true;
        }
        int width = board.size();
        if(width == 0)
        {
            return false;
        }
        m = width;
        int height = board[0].size();
        if(height == 0)
        {
            return false;
        }
        n = height;
        wordLen = word.size();
        visited = new bool* [m];
        int i;
        int j;
        for(i = 0; i < m; i++)
        {
            visited[i] = new bool[n];
        }
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        
        bool result = false;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
            {
                if(subExist(board,i,j,word,0) == true)
                {
                    result = true;
                    break;
                }
            }
        //
        for(i = 0; i < m; i++)
        {
            delete visited[i];
        }
        delete visited;
        
        return result;
        
        
    }
};