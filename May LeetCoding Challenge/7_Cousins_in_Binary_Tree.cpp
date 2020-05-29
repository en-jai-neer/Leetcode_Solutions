In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

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
    void dfs(TreeNode* root, int x, int y, int parent, int depth)
    {
        if(root == NULL)
            return;
        if(root->val == x)
        {
            xParent = parent;
            xDepth = depth;
        }
        else if(root->val == y)
        {
            yParent = parent;
            yDepth = depth;
        }
        else
        {
            dfs(root->left, x, y, root->val, depth+1);
            dfs(root->right, x, y, root->val, depth+1);
        }
    }
    
public:
    int xDepth = -1, yDepth = -1, xParent = -1, yParent = -1;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, -1, 0);
        return xDepth==yDepth && xParent!=yParent;
    }
};
