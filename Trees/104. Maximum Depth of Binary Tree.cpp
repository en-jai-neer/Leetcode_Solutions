class Solution {
private:
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int depthleft = solve(root->left)+1;
        int depthright = solve(root->right)+1;
        return max(depthleft, depthright);
    }
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};
