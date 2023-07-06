//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node, vector<int> adj[], bool vis[], stack<int>&st)
	{
	    vis[node] = true;
	    for(auto x:adj[node])
	    {
	        if(!vis[x])
	        {
	            dfs(x, adj, vis, st);
	        }
	    }
	    st.push(node);//when the DFS for the required element is over we know 
	    //everything after that is covered  
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
//DFS SOLUTION

        // bool vis[V] = {false};
        // vector<int> ans;
        // stack<int> st;
        // for(int i=0;i<V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         dfs(i, adj, vis, st);
        //     }
        // }
        // while(!st.empty())
        // {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;
        
//BFS SOLUTION

        int inDegree[V] = {0};
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
                inDegree[x]++;
        }
        queue<int> q;
        //if indegree is 0 then it's in the answer
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
        return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends