//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, bool vis[], vector<int> adj[])
    {
        vis[src] = true;
        queue<pair<int, int> > q;//node, parent
        q.push({src, -1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=true;
                    q.push({x, node});
                }
                else if(parent!=x)//means it had been marked and it is not parent
                    return true;
            }
        }
        return false;
    }
    bool detectDFS(int node, int parent, bool vis[], vector<int> adj[])
    {
        vis[node] = true;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                if(detectDFS(x, node, vis, adj)==true)
                    return true;
            }
            else if(x!=parent)//means we met a marked node which is not parent
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        bool vis[V] = {false};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detectDFS(i, -1, vis, adj)==true)
                    return true;
            }
        }
        return false;
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