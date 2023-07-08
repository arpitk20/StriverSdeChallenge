//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int, int>> adj[n+1];//1st node, 2nd node and weight
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int> dist(n+1, 1e9);
        dist[1] = 0;
        vector<int> parent(n+1);
        for(int i=1;i<n+1;i++)
            parent[i] = i;
        pq.push({0, 1});//weight, source
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int weight = p.first;
            int node = p.second;
            for(auto x:adj[node])
            {
                if(weight+x.second<dist[x.first])
                {
                    parent[x.first] = node;
                    dist[x.first] = x.second+weight;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        if(dist[n]==1e9)
            return {-1};
        vector<int> path;
        int node = n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);//will be left out
        reverse(path.begin(), path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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