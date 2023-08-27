//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<int> adj[], bool vis[], vector<int>& dist)
    {
        vis[node] = true;
        for(auto x:adj[node])
        {
            if(dist[node]+1<dist[x])
            {
                dist[x] = 1+dist[node];
                dfs(x, adj, vis, dist);
            }
        }
        return ;
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool vis[N] = {false};
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, dist);
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
                dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends