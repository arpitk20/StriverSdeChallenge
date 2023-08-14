class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &output, int index)
    {
        int n = candidates.size();
        if(target==0)
        {
            ans.push_back(output);
            return;
        }
        if(index>=n)
            return;
        if(target<0)
            return;
        //include
        output.push_back(candidates[index]);
        solve(candidates, target-candidates[index], ans, output, index+1);
        output.pop_back();
        //exclude
        while(index<n-1 && (candidates[index]==candidates[index+1]))
            index++;
        solve(candidates, target, ans, output, index+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ans, output, index);
        return ans;
    }
};