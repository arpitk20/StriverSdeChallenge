class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    bool search(int i, int j, vector<vector<char>>& board, string &word, int k)
    {
        int n = board.size();
        int m = board[0].size();
        if(k==word.size())
            return true;
        if(i<0||j<0||i==n||j==m||board[i][j]!=word[k])
            return false;
        char ch = word[k];
        board[i][j] = '#';
        for(int a = 0;a<4;a++)
        {
            if(search(i+drow[a], j+dcol[a], board, word, k+1))
                return true;
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                    if(search(i, j, board, word, 0))
                        return true;
            }
        }
        return false;
    }
};