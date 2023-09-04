//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    void bfs(int row, int col, vector<vector<char>> &ans, vector<vector<int>> &vis)
    {
        int n = ans.size();
        int m = ans[0].size();
        
        vis[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&ans[nrow][ncol]=='O')
                {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
        return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<char>> ans = mat;
        vector<vector<int>> vis(n, vector<int>(m, false));
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && mat[i][0]=='O')
                bfs(i, 0, ans, vis);
            if(!vis[i][m-1] && mat[i][m-1]=='O')
                bfs(i, m-1, ans, vis);
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && mat[0][j]=='O')
                bfs(0, j, ans, vis);
            if(!vis[n-1][j] && mat[n-1][j]=='O')
                bfs(n-1, j, ans, vis);
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && ans[i][j]=='O')
                ans[i][j] = 'X';
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends