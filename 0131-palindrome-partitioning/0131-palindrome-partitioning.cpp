class Solution {
public:
    bool isPallindrome(string& s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
            else
                continue;
        }
        return true;
    }
    void solve(string& s, vector<vector<string>>& res, vector<string>& output, int index)
    {
        if(index>=s.size())
            res.push_back(output);
        for(int i=index;i<s.size();i++)
        {
            if(isPallindrome(s, index, i))
            {
                output.push_back(s.substr(index, i-index+1));
                solve(s, res, output, i+1);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> output;
        int index = 0;
        solve(s, res, output, index);
        return res;
    }
};