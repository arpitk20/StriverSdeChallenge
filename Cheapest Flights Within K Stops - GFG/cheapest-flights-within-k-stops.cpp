//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        //Simple djikstra will now work, as we may have shorter destination but it is 
        //not reachable
        //Instead we use no of stops as first entry of the PQ so that we exhause all the 
        //stops and get the shortes distance till destination
        vector<pair<int, int>> adj[n];
        for(auto x:flights)
        {
            adj[x[0]].push_back({x[1], x[2]});//x[0]->x[1] with cost x[2]
        }
        vector<int> cost(n, 1e9);
        //PQ is not needed since the elements would be pushed in ascending order only
        queue<pair<int, pair<int, int>>> q;//stops, node, price
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            
            if(stops>=K+1)//we used all the stops
                continue;
            else
            {
                for(auto x:adj[node])
                {
                    int adjNode = x.first;
                    int travelPrice = x.second;//on that node travelPrice
                    if(travelPrice+price<cost[adjNode] && stops<=K)
                    {
                        cost[adjNode] = travelPrice+price;
                        q.push({stops+1, {adjNode, cost[adjNode]}});
                    }
                }
            }
        }
        if(cost[dst]==1e9)
            return -1;
        return cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends