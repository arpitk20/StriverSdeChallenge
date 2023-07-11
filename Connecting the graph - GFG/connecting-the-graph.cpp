//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    class DisjointSet 
    {
    vector<int> rank, parent, size; 
    public: 
        DisjointSet(int n) {

        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    
        int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }//find ultimate parent
    
    
        void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
    };
    int Solve(int V, vector<vector<int>>& edge) {
        
        //for n components, I would need n-1 edges
        DisjointSet ds(V);
        int cntExtra = 0;
        for(auto x:edge)
        {
            int u = x[0] ; 
            int v = x[1];
            if(ds.findUPar(u)==ds.findUPar(v))
            {
                cntExtra++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        int cntComponent = 0;
        for(int i=0;i<V;i++)
        {
            if(ds.findUPar(i)==i)
                cntComponent++;
        }
        int ans = cntComponent-1;
        if(cntExtra>=ans)
            return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends