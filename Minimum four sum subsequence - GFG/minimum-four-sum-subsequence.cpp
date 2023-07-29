//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int ar[], int n){
        
        // if elements are less than or equal to 4
    if (n <= 4)
        return *min_element(ar, ar + n);
 
    // save start four element as it is
    int sum[n];
    sum[0] = ar[0];
    sum[1] = ar[1];
    sum[2] = ar[2];
    sum[3] = ar[3];
 
    // compute sum[] for all rest elements
    for (int i = 4; i < n; i++)
        sum[i] = ar[i] + (*min_element(sum + i - 4, sum + i));
 
    // Since one of the last 4 elements must be
    // present
    return *min_element(sum + n - 4, sum + n);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends