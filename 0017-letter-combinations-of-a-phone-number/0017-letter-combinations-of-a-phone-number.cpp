class Solution {
public:
    void solve(string digits, vector<string>& pad, string& temp, vector<string>& output, int index)
    {
        if(index==digits.size())
        {
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(int i=0;i<value.size();i++)
        {
            temp.push_back(value[i]);
            solve(digits, pad, temp, output, index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
       if(digits.size()==0)
           return {};
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        vector<string> output;
        solve(digits, pad, temp, output, 0);
        return output;
    }
};