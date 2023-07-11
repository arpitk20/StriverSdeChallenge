/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    set<TreeNode*> visited;
    map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    void findParent(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
        {
            parent[root->left] = root;
            findParent(root->left);
        }
        if(root->right)
        {
            parent[root->right] = root;
            findParent(root->right);
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        findParent(root);
        dfs(target, k);
        return ans;
    }
    void dfs(TreeNode* root, int k)
    {
        if(visited.find(root)!=visited.end())
            return;
        visited.insert(root);
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        if(root->left)
            dfs(root->left, k-1);
        if(root->right)
            dfs(root->right, k-1);
        
        TreeNode* p = parent[root];
        if(p)
            dfs(p, k-1);
    }
};