class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), start = 0, end = n-1;
        if(n == 1 || nums[end] > nums[0])
            return nums[0];
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            
            if (nums[mid-1] > nums[mid])
                return nums[mid];
            
            if(nums[mid] > nums[0])
                start = mid+1;
            else
                end = mid-1; 
        }
        return -1;
    }
};
