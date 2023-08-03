class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int dp[n+1][amount+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<amount+1;j++)
            {
                if(j==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1e9;
            }
                            
        for(int i=0;i<amount+1;i++)
        {
            if(i%coins[0]==0)
                dp[1][i] = i/coins[0];
        }
        for(int i=1;i<n+1;i++)
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        
        if(dp[n][amount]==1e9)
            return -1;
        return dp[n][amount];
    }
};