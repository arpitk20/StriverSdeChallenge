//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans = "";
        string temp = "";
        for(int i=S.size()-1;i>=0;i--)
        {
            if(S[i]=='.')
            {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans = ans + ".";
                temp = "";
            }
            else
            {
                temp.push_back(S[i]);
            }
        }
        //Last word was not dealt with, but it is stored in temp
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends