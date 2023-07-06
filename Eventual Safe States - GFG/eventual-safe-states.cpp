//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfsCheck(int node, int vis[], int pathVis[], vector<int> adj[], int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfsCheck(it, vis, pathVis, adj, check)==true)
                {
                    check[node] = 0;//definitely not a safe node since a cycle
                    return true;
                }
            }
            //if the node has been visited and has been visited on the same path
            else if(vis[it] && pathVis[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;//dfs is complete means no cycle
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    
//DFS SOLUTION

        //can be solved using cycle detect or topological sort
        // int vis[V] = {0};
        // int pathVis[V] = {0};
        // int check[V] = {0};//to mark safe nodes
        // vector<int> safeNodes;
        
        // for(int i=0;i<V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         dfsCheck(i, vis, pathVis, adj, check);
        //     }
        // }
        // for(int i=0;i<V;i++)
        //     if(check[i]==1)
        //         safeNodes.push_back(i);

//BFS TOPOLOGICAL SORT SOLUTION
        vector<int> safeNodes;
        //we reverse the graph and insert the appropriate nodes
        vector<int> adjRev[V];
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
                adjRev[x].push_back(i);
        }
        int inDegree[V] = {0};
        for(int i=0;i<V;i++)
        {
            for(auto x:adjRev[i])
                inDegree[x]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++)
            if(inDegree[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto x:adjRev[node])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
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