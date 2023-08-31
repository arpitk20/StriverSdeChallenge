class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int a = m-1;
        int b = n-1;
        int i = m+n-1;
        while(a>=0 && b>=0)
        {
            if(nums1[a]<=nums2[b])
                nums1[i--] = nums2[b--];
            else
                nums1[i--] = nums1[a--];
        }
        while(b>=0)
        {
            nums1[i--] = nums2[b--];
        }
        //We need not mess with the nums1 as it would be in sorted order
    }
};