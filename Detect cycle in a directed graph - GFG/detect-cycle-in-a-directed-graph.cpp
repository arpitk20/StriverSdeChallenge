//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int node, int vis[], int pathVis[], vector<int> adj[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfsCheck(it, vis, pathVis, adj)==true)
                    return true;
            }
            //if the node has been visited and has been visited on the same path
            else if(vis[it] && pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        
//DFS SOLUTION

        // for(int i=0;i<V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         if(dfsCheck(i, vis, pathVis, adj)==true)
        //             return true;
        //     }
        // }
        // return false;
        
//BFS SOLUTION

        int inDegree[V] = {0};
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
                inDegree[x]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
            if(inDegree[i]==0)
                q.push(i);
              
        vector<int> topo;  
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto x:adj[node])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
        }
        if(topo.size()==V)
            return false;
        return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends