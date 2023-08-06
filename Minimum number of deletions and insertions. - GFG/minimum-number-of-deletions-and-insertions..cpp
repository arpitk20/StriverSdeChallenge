//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
	    int m = str2.size();
	    int deletions = str1.size()-lcs(n, m, str1, str2);
	    int insertions = str2.size()-lcs(n, m , str1, str2);
	    
	    return insertions+deletions;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends