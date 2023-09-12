//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        
        if(N==1)
            return 0;
        long long cnt = 1;
        long long i = 2;
        while((i*i) <= N)
        {
            if(N%i==0)
            {
                cnt += i;
                if(i==N/i)
                {
                    i++;
                    continue;
                }
                cnt += N/i;
            }
            i++;
        }
        
        return (cnt==N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends