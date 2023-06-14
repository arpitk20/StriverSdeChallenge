class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n)
    {
        //for copying multiple times
        int duprow = row;
        int dupcol = col;
        
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        
        col = dupcol;
        while(col>=0 && row>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row--;
            col--;
        }
        
        col = dupcol;
        row = duprow;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        
        return true;
        
    }
    void solve(int col, vector<string>& board, vector<vector<string> >& res, int n)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)//we're checking every single column
        {
            if(isSafe(row, col, board, n))//if a particular cell is safe
            {
                board[row][col] = 'Q';//we update that
                solve(col+1, board, res, n);
                board[row][col] = '.';//Backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
            board[i] = s;
        
        solve(0, board, res, n);
        return res;
    }
};