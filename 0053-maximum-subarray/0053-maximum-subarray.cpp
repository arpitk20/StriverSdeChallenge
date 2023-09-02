class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int sum = INT_MIN;
        int currSum = 0;
        for(int i=0;i<n;i++)
        {
            currSum += nums[i];
            sum = max(sum, currSum);
            if(currSum<0)
                currSum = 0;
        }
        return sum;
    }
};