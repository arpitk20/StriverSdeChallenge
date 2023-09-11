class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left, right;
        stack<pair<int, int>> s1, s2;//index, element
        int pseudoIndex1 = -1, pseudoIndex2 = n;
        
        for(int i=0;i<n;i++)
        {
            if(s1.empty())
                left.push_back(pseudoIndex1);
            else if(!s1.empty() && s1.top().second < heights[i])
                left.push_back(s1.top().first);
            else if(!s1.empty() && s1.top().second >= heights[i])
            {
                while(!s1.empty() && s1.top().second >= heights[i])
                    s1.pop();
                if(s1.empty())
                    left.push_back(pseudoIndex1);
                else
                    left.push_back(s1.top().first);
            }
            s1.push({i, heights[i]});
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s2.empty())
                right.push_back(pseudoIndex2);
            else if(!s2.empty() && s2.top().second < heights[i])
                right.push_back(s2.top().first);
            else if(!s2.empty() && s2.top().second >= heights[i])
            {
                while(!s2.empty() && s2.top().second >= heights[i])
                    s2.pop();
                if(s2.empty())
                    right.push_back(pseudoIndex2);
                else
                    right.push_back(s2.top().first);
            }
            s2.push({i, heights[i]});
        }
        reverse(right.begin(), right.end());
        
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            mx = max(mx, heights[i]*(right[i]-left[i]-1));
        }
        return mx;
    }
};