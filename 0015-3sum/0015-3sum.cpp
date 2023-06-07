class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > res = {};
        
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]>0)
                break;
            
            int num = nums[i];//Using this as one of the elements
            if(i==0||nums[i-1]!=nums[i])
            {
                int sum = 0-num;
                int lo = i+1;
                int hi = n-1;
                
                while(lo<hi)
                {
                    if(nums[lo]+nums[hi]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(num);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        
                        while(lo<hi && nums[lo]==nums[lo+1])
                            lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])
                            hi--;
                        
                        lo++;
                        hi--;//for moving ahead of the pointers
                    }
                    else if(nums[lo]+nums[hi] < sum)
                        lo++;
                    else if(nums[lo]+nums[hi] > sum)
                        hi--;
                }
            }
        }
        return res;
    }
};