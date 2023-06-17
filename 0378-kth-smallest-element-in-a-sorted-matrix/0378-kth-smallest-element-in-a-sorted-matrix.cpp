class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {  
        
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        while(lo<=hi)
        {
            int mid = lo + ((hi-lo)>>1);
            int num = 0;
            for(int i=0;i<n;i++)
            {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if(num<k)
                lo = mid+1;
            else 
                hi = mid-1;
        }
        
        return lo;
        
    }
    
//    
       
};