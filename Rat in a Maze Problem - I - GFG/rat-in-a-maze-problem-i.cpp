//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    #define pb push_back
    void findPathHelper(int i, int j, vector<vector<int> >& available, int n, vector<string>& res, string move, vector<vector<int> >& visited)
    {
        if(i==n-1 && j==n-1)
            res.pb(move);
            
        //down
        if(i+1<n && !visited[i+1][j] && available[i+1][j]==1)
        {
            visited[i][j] = 1;//Mark the vertex from which we moved
            findPathHelper(i+1, j, available, n, res, move+'D', visited);
            visited[i][j] = 0;//Setting it back for other operations
        }
        
        //up
        if(i-1>=0 && !visited[i-1][j] && available[i-1][j]==1)
        {
            visited[i][j] = 1;//Mark the vertex from which we moved
            findPathHelper(i-1, j, available, n, res, move+'U', visited);
            visited[i][j] = 0;//Setting it back for other operations
        }
        
        //right
        if(j+1<n && !visited[i][j+1] && available[i][j+1]==1)
        {
            visited[i][j] = 1;//Mark the vertex from which we moved
            findPathHelper(i, j+1, available, n, res, move+'R', visited);
            visited[i][j] = 0;//Setting it back for other operations
        }
        
        
        //left
        if(j-1>=0 && !visited[i][j-1] && available[i][j-1]==1)
        {
            visited[i][j] = 1;//Mark the vertex from which we moved
            findPathHelper(i, j-1, available, n, res, move+'L', visited);
            visited[i][j] = 0;//Setting it back for other operations
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        vector<vector<int> > visited(n, vector<int>(n, 0));
        if(m[0][0]==1)
            findPathHelper(0, 0, m, n, res, "", visited);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends