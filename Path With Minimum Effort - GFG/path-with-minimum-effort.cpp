//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;//absolute dist, row, col
        //min heap because whenever we reach the source, we'll reach via tha path which 
        //has the minimum difference of all the maximum heights
        vector<vector<int>> effort(n, vector<int>(m, 1e9));//effort from source to cell
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while(!pq.empty())
        {
            int diff = pq.top().first;//maximum difference for that particular path
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)
                return diff;
            
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort = max(abs(heights[nrow][ncol]-heights[row][col]), diff);
                    //stores maximum effort till now
                    if(newEffort<effort[nrow][ncol])
                    {
                        pq.push({newEffort, {nrow, ncol}});
                        effort[nrow][ncol] = newEffort;
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