//Recursive
vector<int> ans;

void solve(TreeNode* root)
{
    if(root == NULL)
        return;
    solve(root->left);
    solve(root->right);
    ans.push_back(root->val);
}

vector<int> Solution::postorderTraversal(TreeNode* A) {
    ans.clear();
    solve(A);
    return ans;
}

//Iterative
vector<int> Solution::postorderTraversal(TreeNode* A) {
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
        TreeNode* temp = st.top()->right;
        if(temp == NULL)
        {
            while(!st.empty() && temp == st.top()->right)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
            }
        }
        else
            cur = temp;
    }
    return ans;
}
