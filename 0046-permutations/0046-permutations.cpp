class Solution {
    
public:
    void solve(vector<int>& nums, vector<vector<int> >& res, vector<int>& output, int index)
    {
        int n = nums.size();
        if(index==n)
        {
            res.push_back(output);
            return;
        }
        for(int i=index;i<n;i++)
        {
            swap(nums[index], nums[i]);
            output.push_back(nums[index]);
            solve(nums, res, output, index+1);
            output.pop_back();
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> output;
        int index = 0;
        solve(nums, res, output, index);
        return res;
    }
};