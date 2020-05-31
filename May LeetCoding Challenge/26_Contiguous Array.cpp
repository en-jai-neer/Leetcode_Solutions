Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            nums[i] == 1 ? sum++ : sum--;
            mp.count(sum) ? ans = max(ans, i - mp[sum] + 1) : mp[sum] = i+1;
        }
        return ans;
    }
};
