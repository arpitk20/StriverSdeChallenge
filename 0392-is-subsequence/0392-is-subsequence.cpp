class Solution {
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
    bool isSubsequence(string s, string t) {
        
        return (s.size()==lcs(s.size(), t.size(), s, t));
    }
};