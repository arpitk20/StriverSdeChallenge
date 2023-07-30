//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    void subsetSum(int arr[], int n, int sum, vector<vector<bool>>& dp)
    {
        for(int i=0;i<sum+1;i++)
            dp[0][i] = false;
        for(int i=0;i<n+1;i++)
            dp[i][0] = true;
        
        for(int i=1;i<n+1;i++)
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
	int minDifference(int arr[], int n)  { 
        
        int mn = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += arr[i];
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        subsetSum(arr, n, sum, dp);
        
        for(int i=0;i<=sum/2;i++)
        {
            if(dp[n][i])
            {
                mn = min(mn, sum - 2*i);
            }
        }
        return mn;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends