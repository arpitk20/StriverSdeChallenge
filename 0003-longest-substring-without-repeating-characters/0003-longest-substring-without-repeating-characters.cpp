class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int left = 0;
        int ans = 0;
        unordered_set<char> st;
        
        for(int right = 0;right<n;right++)
        {
            if(st.find(s[right])!=st.end())
            {
                while(left<right && st.find(s[right])!=st.end())
                {
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};