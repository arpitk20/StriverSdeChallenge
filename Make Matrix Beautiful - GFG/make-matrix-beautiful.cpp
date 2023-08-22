//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int total = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int columnSum = 0, rowSum = 0;
            for(int j=0;j<n;j++)
            {
                rowSum += matrix[i][j];
                columnSum += matrix[j][i];
                total += matrix[i][j];
            }
            mx = max(mx, max(columnSum, rowSum));
        }
        
        return (n*mx - total);//we have to make sum of each row and col equal to max
        //sum
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends