//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> adj[N];
	    for(auto x:prerequisites)
	    {
	        adj[x.second].push_back(x.first);
	    }
	    
	    vector<int> topo;
	    int inDegree[N] = {0};
	    for(int i=0;i<N;i++)
	    {
	        for(auto x:adj[i])
	            inDegree[x]++;
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(inDegree[i]==0)
	            q.push(i);
	    }
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
	    return (topo.size()==N);
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
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends