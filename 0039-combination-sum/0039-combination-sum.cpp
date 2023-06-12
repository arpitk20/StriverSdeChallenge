class Solution {
public:
    #define pb push_back
    void solve(vector<vector<int>>&res, vector<int>& output, vector<int>&candidates, int target, int index)
    {
        int n = candidates.size();
        
        if(target==0)
        {
            res.pb(output);
            return;
        }
        
        if(target<0)//Can't be achieved with this number
            return;
        
        if(index==n)//can't be achieved here as well
            return;
        
        //exclude
        solve(res, output, candidates, target, index+1);
        
        //include
        output.pb(candidates[index]);
        solve(res, output, candidates, target-candidates[index], index);
        output.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> output;
        int index = 0;
        solve(res, output, candidates, target, index);
        return res;
    }
};