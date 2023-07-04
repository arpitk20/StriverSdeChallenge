//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int row, int col, int newColor, 
    vector<vector<int>>& image, vector<vector<int>>& ans, int iniColor)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        int nrow = row, ncol = col;//initial row and col
        //four directions up, left, right , bot
        //UP
        nrow = row-1;
        if(nrow>=0 && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow, ncol, newColor, image, ans, iniColor);
        }
        //DOWn
        nrow = row+1;
        if(nrow<n && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow, ncol, newColor, image, ans, iniColor);
        }
        nrow = row, ncol = col-1;
        if(ncol>=0 && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow, ncol, newColor, image, ans, iniColor);
        }
        ncol = col+1;
        if(ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow, ncol, newColor, image, ans, iniColor);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<int> > ans = image;
        int iniColor = image[sr][sc];
        dfs(sr, sc, newColor, image, ans, iniColor);
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