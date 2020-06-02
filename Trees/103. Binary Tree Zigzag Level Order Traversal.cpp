//Using double ended queue
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode* > dq;
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        dq.push_back(root);
        int curlevel = 0;
        while(!dq.empty())
        {
            vector<int> level;
            int n = dq.size();
            for(int i = 0; i < n; i++)
            {
                if(curlevel % 2 == 0)
                {
                    TreeNode* cur = dq.front();
                    level.push_back(cur->val);
                    dq.pop_front();
                    if(cur->left)
                        dq.push_back(cur->left);
                    if(cur->right)
                        dq.push_back(cur->right);
                }
                else
                {
                    TreeNode* cur = dq.back();
                    level.push_back(cur->val);
                    dq.pop_back();
                    if(cur->right)
                        dq.push_front(cur->right);
                    if(cur->left)
                        dq.push_front(cur->left);
                }
            }
            curlevel++;
            ans.push_back(level);
        }
        return ans;
    }
};

//Using single queue
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        q.push(root);
        int curlevel = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level(n);
            for(int i = 0; i < n; i++)
            {
                TreeNode* cur = q.front();
                int ind = curlevel % 2 == 0 ? i : n - i -1;
                level[ind] = cur->val;
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            curlevel++;
            ans.push_back(level);
        }
        return ans;
    }
};
