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
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        //pair<int, pair<int, int> > p->to store the elements
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> > > > pq;
        //K is the row and col size
        for(int i=0;i<K;i++)
            pq.push({arr[i][0], {i, 0}});//element, row, col
        while(!pq.empty())
        {
            int value = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            ans.push_back(value);
            pq.pop();
            if(col<K-1)//we are within the limits of the matrix
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