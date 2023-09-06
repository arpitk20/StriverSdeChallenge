//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if(start==end)
            return 0;
            
        int n = arr.size();
        
        vector<int> dist(1e5, 1e9);
        queue<pair<int, int>> q;
        q.push({start, 0});//node, steps
        
        while(!q.empty())
        {
            int num = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                int x = num*arr[i]%mod;
                if(x==end)
                    return steps+1;
                if(steps+1<dist[x])
                {
                    dist[x] = steps+1;
                    q.push({x, steps+1});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends