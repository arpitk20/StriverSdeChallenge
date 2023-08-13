class Solution {
public:
    #define pb push_back
    void solve(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &output, int index, int target)
    {
        if(target==0)
        {
            ans.pb(output);
            return ;
        }
        if(index==candidates.size())
        {
            return;//reached the end with not sum, so not answer
        }
        if(target<0)//can't reach
            return;
        
        //exclude
        solve(candidates, ans, output, index+1, target);
        //include
        output.pb(candidates[index]);
        solve(candidates, ans, output, index, target-candidates[index]);
        output.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(candidates, ans, output, index, target);
        return ans;
    }
};