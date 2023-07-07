//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node, int vis[], vector<pair<int, int>> adj[], stack<int>& st)
    {
        vis[node] = true;
        for(auto x:adj[node])
            if(!vis[x.first])
                dfs(x.first, vis, adj, st);
        st.push(node);
        return;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        //Step 1: Do a Topo Sort
        vector<pair<int, int> > adj[N];
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            adj[u].push_back({edges[i][1], edges[i][2]});//0->1 and edge, 2nd is the weight
        }
        
        int vis[N] = {0};
        stack<int> st;//when the dfs call is over, push the element into the stack
        //for topo sort
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
                dfs(i, vis, adj, st);
        }
        
        //Step 2: Take nodes out of the stack and relax the edges
        vector<int> dist(N, 1e9);
        dist[0] = 0;//src node is marked zero
        while(!st.empty())
        {
            int node = st.top();    
            st.pop();
            for(auto x:adj[node])
            {
                int v = x.first;
                int wt = x.second;
                if(dist[node]+wt < dist[v])
                    dist[v] = dist[node] + wt;//if it is easier to reach via parent
            }
        }
        for(int i=0;i<N;i++)
            if(dist[i]==1e9)
                dist[i] = -1;
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends