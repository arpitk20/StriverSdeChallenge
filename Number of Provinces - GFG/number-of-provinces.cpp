//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adjList[], int vis[], vector<int>& ans)
    {
        ans.push_back(node);
        vis[node] = 1;
        for(auto x:adjList[node])
        {
            if(!vis[x])
            {
                dfs(x, adjList, vis, ans);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<int> adjList[V];
        for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
        {
            if(adj[i][j] != 0)
                adjList[i].push_back(j);
        }
        int cnt = 0;
        int vis[V] = {0};
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i, adjList, vis, ans);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends