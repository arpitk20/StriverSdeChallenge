class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int index)
    {
        if(index==nums.size())
        {
            ans.push_back(output);
            return;
        }
        output.push_back(nums[index]);
        solve(nums, ans, output, index+1);
        output.pop_back();
        
        //avoiding the same elements
        while(index<nums.size()-1 && (nums[index]==nums[index+1]))
            index++;
        solve(nums, ans, output, index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        //we need to sort for comparison in solve function
        sort(nums.begin(), nums.end());
        solve(nums, ans, output, index);
        return ans;
    }
};