class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        ans.push_back(intervals[0]);
        for(int i=0;i<n;i++)
        {
            if(ans[ans.size()-1][1] >= intervals[i][0])//compare the last and the first value
                ans[ans.size()-1][1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};