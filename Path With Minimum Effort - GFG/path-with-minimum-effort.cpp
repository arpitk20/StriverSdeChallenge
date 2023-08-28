//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    int MinimumEffort(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        pq.push({0, {0, 0}});//effort, row, col
        effort[0][0] = 0;
        
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1)
                return effort[row][col];
                
            for(int i=0;i<4;i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m)
                {
                    int newEffort = max(diff, abs(heights[nrow][ncol]-heights[row][col]));
                    if(newEffort<effort[nrow][ncol])
                    {
                        effort[nrow][ncol] = newEffort;
                        pq.push({effort[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends