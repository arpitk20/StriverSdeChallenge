//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& vis, int iniColor, int newColor)
    {
        int n = ans.size();
        int m = ans[0].size();
        ans[row][col] = newColor;
        vis[row][col] = 1;
        for(int i=0;i<4;i++)
        {
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&!vis[nrow][ncol]&&ans[nrow][ncol]==iniColor)
                dfs(nrow, ncol, ans, vis, iniColor, newColor) ;   
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int iniColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(sr, sc, ans, vis, iniColor, newColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends