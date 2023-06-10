//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int index, int sum, vector<int>& arr, int N, vector<int>& subsetSum)
    {
        if(index==N)
        {
            //We reached the end
            subsetSum.push_back(sum);
            return;
        }
        //Leaving the element
        solve(index+1, sum, arr, N, subsetSum);
        
        //Taking the element
        solve(index+1, sum+arr[index],arr ,N , subsetSum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subsetSum;
        solve(0, 0, arr, N, subsetSum);
        sort(subsetSum.begin(), subsetSum.end());
        return subsetSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends