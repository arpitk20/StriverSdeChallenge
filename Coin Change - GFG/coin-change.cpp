//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    typedef long long int ll;
    long long int count(int coins[], int n, int sum) {

        ll dp[n+1][sum+1];
        for(int i=0;i<sum+1;i++)
            dp[0][i] = 0;
        for(int i=0;i<n+1;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<n+1;i++)
        for(int j=1;j<sum+1;j++)
        {
            if(coins[i-1]<=j)
            {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; 
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends