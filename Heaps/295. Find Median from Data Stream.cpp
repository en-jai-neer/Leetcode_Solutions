class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.empty() == true && high.empty() == true)
        {
            low.push(num);
            return;
        }
        if(low.size() > high.size())
        {
            low.push(num);
            high.push(low.top());
            low.pop();
        }
        else
        {
            high.push(num);
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        double f;
        if(high.size() == low.size())
        {
            f = (high.top() + low.top())*0.5;
        }
        else
        {
            if(low.size() > high.size())
                f = low.top();
            else
                f = high.top();
        }
        return f;
    }
};


class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> ms;
    multiset<int>::iterator mid;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
        int n = ms.size();
        if(n == 1)
            mid = ms.begin();
        else if(num >= *mid)
        {
            if(n % 2 == 0)
                mid = next(mid);
        }
        else
        {
            if(n % 2 == 1)
                mid = prev(mid);
        }
    }
    
    double findMedian() {
        int n = ms.size();
        auto it = mid;
        double f = *it;
        if(n % 2 == 0)
        {
            it--;
            f += *it;
            f /= 2;
        }
        return f;
    }
};
