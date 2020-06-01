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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode* > st;
        TreeNode* cur = root;
        while(!st.empty() || cur != NULL)
        {
            while(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            cur = cur->right;
        }
        return ans;
    }
};
