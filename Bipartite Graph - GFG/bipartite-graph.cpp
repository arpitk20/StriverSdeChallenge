//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    queue<int> q;
	    vector<int> color(V, -1);
	    for(int i=0;i<V;i++)
	    {
            if(color[i]==-1)
            {
                color[i] = 0;
                q.push(i);
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(auto x:adj[node])
                    {
                        if(color[x]==color[node])
                            return false;
                        else if(color[x]==-1)
                        {
                            color[x] = (color[node]+1)%2;
                            q.push(x);
                        }
                    }
                }
            }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends