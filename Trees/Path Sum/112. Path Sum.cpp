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

//Iterative DFS (preorder)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        stack<pair<TreeNode *, int>> st;
        st.push({root, root->val});
        while(!st.empty())
        {
            int k = st.top().second;
            TreeNode* cur = st.top().first;
            st.pop();
            if(cur->left == NULL && cur->right == NULL && sum == k)
                return true;
            if(cur->right)
                st.push({cur->right, k + cur->right->val});
            if(cur->left)
                st.push({cur->left, k + cur->left->val});
        }
        return false;
    }
};

//Iterative BFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        queue<pair<TreeNode *, int>> q;
        q.push({root, root->val});
        while(!q.empty())
        {
            int k = q.front().second;
            TreeNode* cur = q.front().first;
            q.pop();
            if(cur->left == NULL && cur->right == NULL && sum == k)
                return true;
            if(cur->left)
                q.push({cur->left, k + cur->left->val});
            if(cur->right)
                q.push({cur->right, k + cur->right->val});
        }
        return false;
    }
};
