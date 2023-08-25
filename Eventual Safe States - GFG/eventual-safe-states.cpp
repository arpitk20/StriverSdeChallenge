//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        vis[i] = 1;
        
        for(auto n : adj[i])
        {
            if(vis[n] == 0)
            {
                if(dfs(n, adj, vis)) return true;
            }
            else if (vis[n] == 1) return true;
        }
        
        vis[i] = 2;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        /*
            0 -> unvisited node
            1 -> visited node
            2 -> visited previously in current path
            3 -> safe node
        */
        vector<int> vis (V, 0);
        vector<int> ans;
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0) 
            {
                dfs(i, adj, vis);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 2) ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends