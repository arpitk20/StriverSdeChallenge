//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int> > &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int> > q;
        q.push({row, col});
        vis[row][col] = 1;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //Traverse in the neighbors and mark them if needed
            for(int neighRow = -1;neighRow<=1;neighRow++)
            {
                for(int neighCol = -1;neighCol<=1;neighCol++)
                {
                    int nrow = row+neighRow;//neighboring row
                    int ncol = col+neighCol;//neighboring col
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> >vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends