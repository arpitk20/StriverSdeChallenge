//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPallindrome(string str, int i, int j)
    {
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string str, int i, int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(isPallindrome(str, i, j))
            return 0;
        
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int left, right;
            
            if(dp[i][k]!=-1)
                left = dp[i][k];
            else
                left = solve(str, i, k);
                
                
            if(dp[k+1][j]!=-1)
                right = dp[k+1][j];
            else
                right = solve(str, k+1, j);
                
                
            int tempAns = left+1+right;
            mn = min(mn, tempAns);
        }
        return dp[i][j] = mn;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        int n = str.size();
        return solve(str, 0, n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends