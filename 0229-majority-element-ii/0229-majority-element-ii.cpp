class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cnt1 = 0, cnt2 = 0;
        int ele1 = -1, ele2 = -1;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i])
                cnt1++;
            else if(ele2==nums[i])
                cnt2++;
            else if(cnt1==0)
            {
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0)
            {
                ele2 = nums[i];
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
        int x = (n/3);
        cnt1 = cnt2 = 0;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i])
                cnt1++;
            else if(ele2==nums[i])
                cnt2++;
        }
        
        vector<int> ans;
        
        if(cnt1>x)
            ans.push_back(ele1);
        if(cnt2>x)
            ans.push_back(ele2);
        
        return ans;
    }
};