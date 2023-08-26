//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char, int> mp;
        int first = 0, last = 0;
        int n = s.size();
        int ans = -1;
        
        while(last<n)
        {
            mp[s[last]]++;
            while(mp.size()>k)
            {
                mp[s[first]]--;
                if(mp[s[first]]==0)
                    mp.erase(s[first]);
                first++;
            }
            if(mp.size()==k)
                ans = max(ans, last-first+1);
            last++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends