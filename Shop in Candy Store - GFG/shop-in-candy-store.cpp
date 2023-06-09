//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies, candies+n);
        
        int minMoney = 0;
        int buy = 0;
        int free = n-1;
        
        while(buy <= free)
        {
            minMoney = minMoney + candies[buy];//Adding Money
            buy++;//Moving Ahead
            free = free-k;//Removing k candies
        }
        
        buy = n-1;
        free = 0;
        int maxMoney = 0;
        
        while(free <= buy )
        {
            maxMoney = maxMoney + candies[buy];
            buy--;
            free = free + k;
        }
        
        vector<int> v;
        v.push_back(minMoney);
        v.push_back(maxMoney);
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends