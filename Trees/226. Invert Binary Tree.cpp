class Solution {
private:
    TreeNode* solve(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        TreeNode* temp = root->right;
        root->right = solve(root->left);
        root->left = solve(temp);
        return root;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};
