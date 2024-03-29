//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    unordered_map<string, int> mp;
    int solve(string s, int i, int j, bool isTrue)
    {
        //base condn
        if(i>j)
            return 0;
        if(i==j)
        {
            if(isTrue==true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        string temp = to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        //looping
        int ans = 0;
        for(int k=i+1;k<=j-1;k=k+2)
        {
            int lt = solve(s, i, k-1, true);//left true
            int lf = solve(s, i, k-1, false);
            int rt = solve(s, k+1, j, true);
            int rf = solve(s, k+1, j, false);
            
            //for "|" operator
            if(s[k]=='|')
            {
                if(isTrue==true)
                    ans = ans+lt*rf+lf*rt+lt*rt;
                else
                    ans = ans+lf*rf;
            }
            else if(s[k]=='^')
            {
                if(isTrue==true)
                    ans = ans+lf*rt+lt*rf;
                else    
                    ans = ans+lt*rt+lf*rf;
            }
            else if(s[k]=='&')
            {
                if(isTrue==true)
                    ans = ans+lt*rt;
                else
                    ans = ans+lf*rf+lt*rf+lf*rt;
            }
        }
        return mp[temp] = ans%mod;
    }
    int countWays(int n, string s){
        
        mp.clear();
        return solve(s, 0, n-1, true)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends