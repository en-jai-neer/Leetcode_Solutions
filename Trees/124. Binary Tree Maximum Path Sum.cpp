class Solution {
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int maxLeft = solve(root->left);
        int maxRight = solve(root->right);
        ans = max({ans, maxLeft+maxRight+root->val, maxLeft+root->val, maxRight+root->val, root->val});
        return max({maxLeft+root->val, maxRight+root->val, root->val});
    }
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};

class Solution {
    int ans;
private:
    int maxSum(TreeNode* root){
        if(root==NULL)   
            return 0;
        int left = max(0, maxSum(root->left));
        int right = max(0, maxSum(root->right));
        ans = max(ans, left+right+root->val);
        return max(left, right)+root->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxSum(root);
        return ans;
    }
};
