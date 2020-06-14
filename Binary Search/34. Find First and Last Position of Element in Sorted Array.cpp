class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), start = 0, end = n-1;
        vector<int> ans(2, -1);
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                if(mid == 0 || nums[mid-1] != target)
                {
                    ans[0] = mid;
                    break;
                }
                else
                    end = mid-1;
            }
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        start = 0, end = n-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                if(mid == n-1 || nums[mid+1] != target)
                {
                    ans[1] = mid;
                    break;
                }
                else
                    start = mid+1;
            }
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return ans;
    }
};

//Shorter Code
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), start = 0, end = n-1;
        vector<int> ans(2, -1);
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
            if(nums[mid] == target)
                ans[0] = mid;
        }
        start = 0, end = n-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] <= target)
                start = mid+1;
            else
                end = mid-1;
            if(nums[mid] == target)
                ans[1] = mid;
        }
        return ans;
    }
};

//Using upper and lower bounds
lass Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);
        if(n == 0)
            return ans;
        auto start = lower_bound(nums.begin(), nums.end(), target); //1st element greater than or equal to target
        auto end = upper_bound(nums.begin(), nums.end(), target); //1st element greater than target
        if(start == nums.end() || *start != target)
            return ans;
        ans[0] = start - nums.begin();
        ans[1] = end - nums.begin() - 1;
        return ans;
    }
};
