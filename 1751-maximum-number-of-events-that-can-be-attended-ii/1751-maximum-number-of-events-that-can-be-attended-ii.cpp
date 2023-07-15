class Solution {
public:
    int solve(vector<vector<int>>& events, vector<vector<int>> &dp, int n, int pos, int k)
    {
        int i;
        
        if(pos>=n||k==0)
            return 0;
        
        if(dp[pos][k]!=-1)
            return dp[pos][k];
        
        for(i=pos+1;i<n;i++)
        {
            if(events[i][0]>events[pos][1])
                break;
        }
        
        return dp[pos][k] = max(solve(events, dp, n, pos+1, k), events[pos][2]+solve(events, dp, n, i, k-1));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        sort(events.begin(), events.end());
        return solve(events, dp,  n, 0, k);
    }
};