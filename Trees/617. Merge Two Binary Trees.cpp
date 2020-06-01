/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
        root1->val += root2->val;
        root1->left = solve(root1->left, root2->left);
        root1->right = solve(root1->right, root2->right);
        return root1;
    }
    
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return solve(t1, t2);
    }
};
