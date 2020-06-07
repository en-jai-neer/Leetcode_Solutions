//Recursive
vector<int> ans;

void solve(TreeNode* root)
{
    if(root == NULL)
        return;
    solve(root->left);
    ans.push_back(root->val);
    solve(root->right);
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
    ans.clear();
    solve(A);
    return ans;
}


//Iterative
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode* > st;
    TreeNode* cur = A;
    while(cur != NULL || !st.empty())
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
