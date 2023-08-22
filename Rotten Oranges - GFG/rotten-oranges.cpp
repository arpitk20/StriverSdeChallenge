//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        int cntFresh = 0;
        
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
                vis[i][j] = 0;
            if(grid[i][j]==1)
                cntFresh++;
        }
        int tm = 0, cnt = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t);
            
            for(int i=0;i<4;i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 
                && vis[nrow][ncol] != 2)
                {
                    cnt++;
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t+1});
                }
            }
        }

        
        return (cnt==cntFresh)?tm:-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends