class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, pair<int, int>>> q;
        int t = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({t, {i, j}});
            }
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            int tm = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            t = max(tm, t);
            for(int i=0;i<4;i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1)
                {
                    grid[nrow][ncol] = 2;
                    q.push({tm+1, {nrow, ncol}});
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        return t;
    }
};