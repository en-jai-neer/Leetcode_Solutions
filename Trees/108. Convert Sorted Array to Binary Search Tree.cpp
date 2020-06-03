class Solution {
private:
    TreeNode* solve(vector<int>& nums, int low, int high)
    {
        if(low > high)
            return NULL;
        int mid = low + (high - low)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solve(nums, low, mid - 1);
        node->right = solve(nums, mid + 1, high);
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return NULL;
        TreeNode* root = solve(nums, 0, n-1);
        return root;
    }
};
