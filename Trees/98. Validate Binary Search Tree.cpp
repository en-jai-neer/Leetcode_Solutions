//Recursive Inorder with extra O(n) space
class Solution {
private:
    void solve(TreeNode* root)
    {
        if(root == NULL)
            return;
        solve(root->left);
        a.push_back(root->val);
        solve(root->right);
    }
public:
    vector<int> a;
    bool isValidBST(TreeNode* root) {
        solve(root);
        for(int i = 1; i < a.size(); i++)
        {
            if(a[i] <= a[i-1])
                return false;
        }
        return true;
    }
};

//Recursive Inorder
class Solution {
private:
    void solve(TreeNode* root)
    {
        if(root == NULL)
            return;
        solve(root->left);
        if(prev != NULL && prev->val >= root->val)
            ans = false;
        prev = root;
        solve(root->right);
    }
public:
    TreeNode* prev = NULL;
    bool ans = true;
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};

//Iterative Inorder
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode* > st;
        TreeNode* prev = NULL;
        while(root != NULL || !st.empty())
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(prev != NULL && prev->val >= root->val)
                return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
