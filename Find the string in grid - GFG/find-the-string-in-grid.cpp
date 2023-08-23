//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int drow[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dcol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    bool isPossible(int row, int col, vector<vector<char>>& grid, string word)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<8;i++)
        {
            int nrow = row;
            int ncol = col;
            int c = 0;
            while(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&c<word.size()
            &&grid[nrow][ncol]==word[c])
            {
                nrow = nrow + drow[i];
                ncol = ncol + dcol[i];
                c++;
                
                if(c==word.size())
                    return true;
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
	    {
	        if(grid[i][j]==word[0] && isPossible(i, j, grid, word))
	            ans.push_back({i, j});
	    }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends