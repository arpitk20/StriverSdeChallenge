//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int lcs(int n, int m, string s1, string s2)
{
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
        dp[i][0] = 0;
    for(int i=0;i<m+1;i++)
        dp[0][i] = 0;
    for(int i=1;i<n+1;i++)
    for(int j=1;j<m+1;j++){
        if(s1[i-1]==s2[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[n][m];
}
int longestPalinSubseq(string a) {
    
    string b;
    for(int i=a.size()-1;i>=0;i--)
        b.push_back(a[i]);
    return lcs(a.size(), b.size(), a, b);
}
    int findMinInsertions(string S){
        
        return S.size()-longestPalinSubseq(S);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends