//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int K) 
    { 
        
        // int i = 0, j = 0;
        // int sum = 0, ln = 0;
        // while(j<n)
        // {
        //     sum += A[j];
        //     while(sum > K)
        //     {
        //         sum -= A[i];
        //         i++;
        //     }
        //     if(sum==K)
        //     {
        //         ln = max(ln, j-i+1);
        //         j++;
        //     }
        //     else if(sum < K)
        //         j++;
        // }
        // return ln;
        
        // Works only for Positive integers
        
        int ln = 0, sum = 0;
        unordered_map<int, int> mp;//sum, index
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            if(sum==K)
                ln = i+1;
            if(mp.find(sum)==mp.end())
                mp[sum] = i;
            if(mp.find(sum-K)!=mp.end())//0 to j ->sum-K => j to i ->K
                ln = max(ln, i-mp[sum-K]);
        }
        return ln;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends