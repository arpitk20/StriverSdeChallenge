class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        
        int ans = 0;
        int n = arr.size();
        
        unordered_map<int, int> dp;
        for(int i=0;i<n;i++)
        {
            int temp = arr[i]-diff;
            int tempNo = 0;
            
            if(dp[temp])//means element alredy present
                tempNo = dp[temp];
            
            dp[arr[i]] = 1+tempNo;
            
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};