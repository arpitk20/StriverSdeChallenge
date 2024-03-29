//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
            
            int n = str.size();
            string a = str;
            string b = str;
            int dp[n+1][n+1];
            for(int i=0;i<n+1;i++)
            {
                dp[i][0] = 0;
                dp[0][i] = 0;
            }
            for(int  i=1;i<n+1;i++)
            for(int  j=1;j<n+1;j++)
            {
                if(a[i-1]==b[j-1] && i!=j)//since we want different letters
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            return dp[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends