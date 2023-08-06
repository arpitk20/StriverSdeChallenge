//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(string S, vector<string>& ans, int index)
    {
        int n = S.size();
        if(index>=n)
        {
            ans.push_back(S);
            return;
        }
            
        for(int j=index;j<n;j++)
        {
            swap(S[index], S[j]);
            solve(S, ans, index+1);
            swap(S[index], S[j]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        solve(S, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends