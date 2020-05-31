class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> ms;
        for(int i: nums)
        {
            ms.insert(i);
            if(ms.size() > k)
                ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i: nums)
        {
            minh.push(i);
            if(minh.size() > k)
                minh.pop();
        }
        return minh.top();
    }
};
