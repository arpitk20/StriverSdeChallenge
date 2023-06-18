class Solution {
public:
    int hinge(vector<int>& nums)
    {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int mid;
        while(lo<=hi)
        {
            mid = lo + (hi-lo)/2;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            if(nums[mid]<nums[prev]&&nums[mid]<nums[next])
                return mid;
            else if(nums[mid]>=nums[hi])
                lo = mid+1;
            else
                hi = mid-1;
        }
        return -1;
    }
    int binarySearch(vector<int>& nums, int lo, int hi, int target)
    {
        int mid;
        while(lo<=hi)
        {
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n==1)
        {
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
        if(nums[0]<nums[n-1])
        {
            return binarySearch(nums, 0, n-1, target);
        }
        int index = hinge(nums);
        int index1 = binarySearch(nums, 0, index-1, target);
        int index2 = binarySearch(nums, index, n-1, target);
        return max(index1, index2);
        
    }
};