class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<string> level;
            for(int i = 0; i < n; i++)
            {
                TreeNode* cur = q.front();
                if(cur)
                    level.push_back(to_string(cur->val));
                else
                    level.push_back("N");
                q.pop();
                if(cur)
                    q.push(cur->left);
                if(cur)
                    q.push(cur->right);
            }
            vector<string> rev = level;
            reverse(rev.begin(), rev.end());
            if(rev != level)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode* > q;
        if(root == NULL)
            return true;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            if(node1 == NULL && node2 == NULL)
                continue;
            if(node1 == NULL || node2 == NULL)
                return false;
            if(node1->val != node2->val)
                return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};

class Solution {
private:
    bool solve(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == NULL && node2 == NULL)
            return true;
        if(node1 == NULL || node2 == NULL || node1->val != node2->val)
            return false;
        return solve(node1->left, node2->right) && solve(node1->right, node2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return solve(root->left, root->right);
    }
};
