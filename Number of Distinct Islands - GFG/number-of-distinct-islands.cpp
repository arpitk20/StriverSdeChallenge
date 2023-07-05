//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>&grid, vector<vector<int> >&vis,
    vector<pair<int, int> >& v, int row0, int col0)//row0, col0 are base coordinates
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int> >q;
        q.push({row, col});
        vis[row][col] = 1;
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            v.push_back({r-row0, c-col0});
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
        return;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        //To store the distinct islands we will definitels use 
        //SETS
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> >vis(n, vector<int>(m, 0));
        set<vector<pair<int, int> > > st;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                vector<pair<int, int> >v;
                bfs(i, j, grid, vis, v, i, j);
                st.insert(v);
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends