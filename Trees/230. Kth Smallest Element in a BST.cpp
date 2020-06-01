class Solution {
private:
    void inOrder(TreeNode* root)
    {
        if(root == NULL || cur > K)
            return;
        inOrder(root->left);
        cur++;
        if(cur == K)
        {
            ans = root->val;
            return;
        }
        inOrder(root->right);
    }
public:
    int cur = 0, K, ans;
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        inOrder(root);
        return ans;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans, cnt = 0;
        stack<TreeNode* > st;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty())
        {
            while(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            cnt++;
            if(cnt == k)
                return cur->val;
            st.pop();
            cur = cur->right;
        }
        return ans;
    }
};
