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
    int solve(TreeNode* root, int& ans)
    {
        if(!root)
            return 0;
        
        int leftValue = solve(root->left, ans);
        if(leftValue<0)
            leftValue = 0;
        int rightValue = solve(root->right, ans);
        if(rightValue<0)
            rightValue = 0;
        
        if(leftValue + rightValue + root->val > ans)
            ans = leftValue+rightValue+root->val;
        return root->val+max(leftValue, rightValue);
    }
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};