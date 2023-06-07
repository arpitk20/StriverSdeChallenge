class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res = {};
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        if(nums[0]>0)
            return {};
        
        for(int i=0;i<n-2;i++)//So that we get at least 3 elements
        {
            if(nums[i]>0)//If the first element is positive then surely we won't get -ve up ahead since the list is sorted
                break;
            if(i==0||nums[i]!=nums[i-1])//Condition because we have to return unique pairs
            {
                int lo = i+1, hi = n-1;
                while(lo<hi)
                {
                    int sum = 0-nums[i];
                    if(nums[lo]+nums[hi]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        
                        while(lo<hi && nums[lo]==nums[lo+1])//So that we skip same numbers
                            lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])//So that we skip same numbers
                            hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum)
                    {
                        lo++;
                    }
                    else if(nums[lo]+nums[hi]>sum)
                    {
                        hi--;
                    }
                    
                }
            }
        }
        return res;
    }
};