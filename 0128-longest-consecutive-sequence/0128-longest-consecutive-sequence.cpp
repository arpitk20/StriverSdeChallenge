class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
            st.insert(nums[i]);
        int cnt = 0;
        int longest = 0;
        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i]-1)!=st.end())
                continue;
            else
            {
                int temp = nums[i];
                while(st.find(temp)!=st.end())
                {
                    temp++;
                    cnt++;
                }
                longest = max(longest, cnt);
                cnt = 0;
            }
        }
        return longest;
    }
};