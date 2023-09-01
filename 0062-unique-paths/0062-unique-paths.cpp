class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if(i>=m||j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return dp[i][j] = 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        countPaths(0, 0, m, n, dp);
        return dp[0][0];
    }
};