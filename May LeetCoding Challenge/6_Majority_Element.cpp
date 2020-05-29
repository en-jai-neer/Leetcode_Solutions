Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = NULL;
        int counter = 0;
        for(int i:nums)
        {
            if(counter==0)
            {
                candidate = i;
                counter = 1;
            }
            else
            {
                if(i==candidate)
                    counter++;
                else
                    counter--;
            }
        }
        return candidate;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
};
