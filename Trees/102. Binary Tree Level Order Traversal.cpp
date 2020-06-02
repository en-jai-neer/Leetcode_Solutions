//Using 2 Queues
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        queue<TreeNode* > childq;
        if(root == NULL)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            while(!q.empty())
            {
                TreeNode* cur = q.front();
                level.push_back(cur->val);
                q.pop();
                if(cur->left) 
                    childq.push(cur->left);
                if(cur->right)
                    childq.push(cur->right);
            }
            ans.push_back(level);
            swap(q, childq);
        }
        return ans;
    }
};


//Using 1 Queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        if(root == NULL)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* cur = q.front();
                level.push_back(cur->val);
                q.pop();
                if(cur->left) 
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
