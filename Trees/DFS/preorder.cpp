//Recursive
vector<int> ans;

void solve(TreeNode* root)
{
    if(root == NULL)
        return;
    ans.push_back(root->val);
    solve(root->left);
    solve(root->right);
}

vector<int> Solution::preorderTraversal(TreeNode* A) {
    ans.clear();
    solve(A);
    return ans;
}

//Iterative
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode* > st;
    TreeNode* cur = A;
    while(cur != NULL || !st.empty())
    {
        while(cur != NULL)
        {
            ans.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cur = cur->right;
    }
    return ans;
}

//Iterative (Easy)
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode* > st;
    st.push(A);
    while(!st.empty())
    {
        TreeNode* cur = st.top();
        st.pop();
        ans.push_back(cur->val);
        if(cur->right)
            st.push(cur->right);
        if(cur->left)
            st.push(cur->left);
    }
    return ans;
}
