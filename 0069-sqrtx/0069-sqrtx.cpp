class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        int ans;
        int mid = l + (r-l)/2;
        while(l<=r)
        {
            mid = l + (r-l)/2;   
            if(mid==x/mid)
                return ans = mid;
            
            else if(mid<x/mid)
            {
                ans = mid;
                l = mid+1;
            }
            else if(mid > x/mid)
                r = mid-1;
            
            
        }
        
        return ans;
    }
};