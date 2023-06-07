class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int currCount = 0, count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                currCount++;
                count = max(count, currCount);
            }
            else
            {
                currCount = 0;
            }
        }
        return count;
    }
};