/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int& ans, int currAns)
    {
        if(!root)
            return ;
    
        if(!root->left && !root->right)
        {
            currAns += 1;
            ans = min(ans, currAns);
            return;
        }
        
        currAns++;
        solve(root->left, ans, currAns);
        solve(root->right, ans, currAns);
    }
    int minDepth(TreeNode* root) {
        
        int ans = INT_MAX;
        int currAns = 0;
        solve(root, ans, currAns);
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};