Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

Example 1:

Input: num = 16
Output: true

Example 2:

Input: num = 14
Output: false
 
Constraints:

1 <= num <= 2^31 - 1

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) 
            return true;
        long long root = num / 2;
        while(root * root > num)
            root = (root + num / root) / 2;
        return root * root == num;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high)
        {
            long long int mid = low + (high - low)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid < num)
                low = (int)mid + 1;
            else
                high = (int)mid - 1;
        }
        return false;
    }
};
