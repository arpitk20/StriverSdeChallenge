//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int eggDrop(int n, int k) 
    {
        if(k<=1||n<=1)
            return k;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int mn = INT_MAX;
        for(int a=1;a<=k;a++)
        {
            int top, bottom;
            if(dp[n-1][a-1]!=-1)
                bottom = dp[n-1][a-1];
            else
                bottom = eggDrop(n-1, a-1);
                
            if(dp[n][k-a]!=-1)
                top = dp[n][k-a];
            else
                top = eggDrop(n, k-a);
                
            int temp = 1+max(bottom, top);
            mn = min(mn, temp);
        }
        return dp[n][k] = mn;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends