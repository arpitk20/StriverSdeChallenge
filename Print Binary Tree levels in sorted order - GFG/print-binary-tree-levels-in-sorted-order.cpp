//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        vector <vector <int>> ans;

        queue<int> q;
        
        q.push(0);
        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int node = q.front();
                q.pop();
                temp.push_back(arr[node]);
                int left = 2*node+1;
                int right = 2*node+2;
                if(left<n)
                    q.push(left);
                if(right<n)
                    q.push(right);
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends