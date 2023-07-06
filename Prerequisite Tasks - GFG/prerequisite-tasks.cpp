//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
        
        vector<int> adj[V];
        for(auto x:prerequisites)
        {
            adj[x.first].push_back(x.second);
        }
        
        queue<int> q;
        int inDegree[V] = {0};
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
                inDegree[x]++;
        }
        for(int i=0;i<V;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        
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
        
        //now if there is a cycle then we can't complete all our tasks
        if(topo.size()==V)//as there is no cycle
            return true;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends