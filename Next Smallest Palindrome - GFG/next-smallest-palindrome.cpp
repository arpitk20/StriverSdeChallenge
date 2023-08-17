//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    string makePallindrome(string s)
    {
        int a = 0;
        int b = s.size()-1;
        while(a<b)
        {
            s[b] = s[a];
            a++;
            b--;
        }
        return s;
    }
    string solve(string A)
    {
        int n = A.size();
        string temp = makePallindrome(A);
        if(temp>A)
            return temp;
        int carry = 1;//we increase the A[(n/2-1)] to get larger string
        for(int i=(n-1)/2;i>=0;i--)
        {
            int t = A[i]-'0'+carry;
            if(t==10)
            {
                t = 0;
                carry = 1;
            }
            else
                carry = 0;
            A[i] = '0' + t;
        }
        string res;
        if(carry==1)
            res = "1";
        res += A;
        return makePallindrome(res);
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    
	    string A;
	    for(int i=0;i<n;i++)
	        A += num[i]+'0';
	    string res = solve(A);
	    vector<int> ans;
	    for(auto x:res)
	        ans.push_back(x-'0');
	    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends