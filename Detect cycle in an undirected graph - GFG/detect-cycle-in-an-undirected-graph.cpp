//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int node, int parent, vector<int> adj[], int vis[]) {
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, parent});
    
    while (!q.empty()) {
        node = q.front().first;
        parent = q.front().second;
        q.pop();
        
        for (auto x : adj[node]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push({x, node});
            } else if (x != parent) {
                return true; // Cycle found
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (bfs(i, -1, adj, vis))
                return true; // Cycle found
        }
    }
    return false; // No cycle
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends