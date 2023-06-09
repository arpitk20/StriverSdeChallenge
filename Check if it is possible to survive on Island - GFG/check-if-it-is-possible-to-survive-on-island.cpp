//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        
        int sundays = S/7;
        int buyingDays = S-sundays;
        int totalUnits = S*M;
        int ans;
        
        if(totalUnits%N==0)
            ans = totalUnits/N;
            
        else
            ans = totalUnits/N + 1;//We have to go to shop 1 day extra
            
            
        if(ans <= buyingDays)//Since we can't buy on sundays
            return ans;
            
        else
            return -1;
        
            
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends