//Recursive
class Solution {
private:
    bool solve(TreeNode* root, int sum)
    {
        if(root == NULL)
            return false;
        sum -= root->val;
        if(root->left == NULL && root->right == NULL)
            return sum == 0;
        return solve(root->left, sum) || solve(root->right, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return solve(root, sum);
    }
};

//Iterative
