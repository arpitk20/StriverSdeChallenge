//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    typedef pair<int, pair<int, int>> pipii;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        
        vector<int> ans;
        
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        for(int i=0;i<K;i++)
            pq.push({arr[i][0], {i, 0}});
        
        while(!pq.empty())
        {
            int element = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            ans.push_back(element);
            if(col+1<K)
                pq.push({arr[row][col+1], {row, col+1}});
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends