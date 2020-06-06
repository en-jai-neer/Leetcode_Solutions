O(n) space
class Solution {
private:
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        if(mp.count(root))
            return mp[root];
        int left = solve(root->left);
        int right = solve(root->right);
        int prev = root->val;
        if(root->left)
            prev += solve(root->left->left) + solve(root->left->right);
        if(root->right)
            prev += solve(root->right->left) + solve(root->right->right);
        return mp[root] = max(prev, left + right);
    }
public:
    map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        solve(root);
        return mp[root];
    }
};

//O(1) space
class Solution {
private:
    pair<int, int> solve(TreeNode* root)
    {
        if(root == NULL)
            return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int child = left.first + right.first;
        int grandChild = left.second + right.second;
        return {max(grandChild + root->val, child), child};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);
        return ans.first;
    }
};
