class Solution {
private:
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return false;
        bool left = solve(root->left, p, q);
        bool right = solve(root->right, p, q);
        bool cur = root == p || root == q;
        if((left && right) || (left && cur) || (right && cur))
            ans = root;
        return cur || left || right;
    }
    
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
};
