class Solution {
private:
    void solve(TreeNode* root)
    {
        if(root == NULL)
            return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};
