//Recursive Backtracking dfs
class Solution {
private:
    void solve(TreeNode* root, int sum, vector<int>& cur)
    {
        if(root == NULL)
            return;
        cur.push_back(root->val);
        sum -= root->val;
        if(root->left == NULL && root->right == NULL)
            if(sum == 0)
                ans.push_back(cur);
        solve(root->left, sum, cur);
        solve(root->right, sum, cur);
        cur.pop_back();
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur;
        solve(root, sum, cur);
        return ans;
    }
};
