//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        pq.push({0, 0});//weight, node
        int sum = 0;
        
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int node = x.second;
            int weight = x.first;
            if(vis[node]==1)
                continue;
            sum += weight;
            vis[node] = 1;
            
            for(auto a:adj[node])
            {
                int adjNode = a[0];
                int edgeWeight = a[1];
                if(!vis[adjNode])
                    pq.push({edgeWeight, adjNode});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends