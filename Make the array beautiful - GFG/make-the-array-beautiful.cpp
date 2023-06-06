//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        int i=0;
        while(i<arr.size())
        {
            if(st.empty())
                st.push(arr[i]);
            else
            {
                if((arr[i]<0 && st.top()>=0) ||(arr[i]>=0 && st.top()<0))
                    st.pop();
                else
                    st.push(arr[i]);
            }
            i++;
        }
        vector<int> res = {};
        int n = st.size();
        for(i=0;i<n;i++)
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends