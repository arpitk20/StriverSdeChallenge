//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        if(vis[row][col])
            return;
        vis[row][col] = 1; 
        q.push({row, col});
        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
                bfs(i, 0, vis, grid);
            if(!vis[i][m-1] && grid[i][m-1]==1)
                bfs(i, m-1, vis, grid);
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
                bfs(0, j, vis, grid);
            if(!vis[n-1][j] && grid[n-1][j]==1)
                bfs(n-1, j, vis, grid);
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!vis[i][j] && grid[i][j]==1)
                cnt++;
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends