//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(vector<int>& candidates, vector<vector<int>>& res, vector<int>& output, int index, int target)
    {
        int n =candidates.size();
        if(target==0)
        {
            res.push_back(output);
            return;
        }
        if(target<0)
            return;
        if(index==n)
            return;
            
        //include
        output.push_back(candidates[index]);
        solve(candidates, res, output, index+1, target-candidates[index]);
        output.pop_back();
            
        //exclude
        while(index+1<n && candidates[index]==candidates[index+1])
            index++;
        solve(candidates, res, output, index+1, target);
        
        
            
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> output;
        int index = 0;
        solve(candidates, res, output, index, target);
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends