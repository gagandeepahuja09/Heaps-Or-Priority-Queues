class MedianFinder {
public:
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    /** initialize your data structure here. */
    MedianFinder() {
        while (minPQ.size()) minPQ.pop();
        while (maxPQ.size()) maxPQ.pop();
    }
    
    void addNum(int num) {
        if (!minPQ.size()) {
            minPQ.push(num);
        } else if (num < minPQ.top()) {
            // if it's smaller that minPQ's top(smallest element), then push in maxPQ 
            maxPQ.push(num);   
        } else {
            minPQ.push(num);
        }
        // rebalancing
        if ((int)(maxPQ.size() - minPQ.size()) > 1) {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        } else if ((int)(minPQ.size() - maxPQ.size()) > 1) {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }
    }
    
    double findMedian() {
        if (minPQ.size() != maxPQ.size()) {
           return minPQ.size() < maxPQ.size() ? maxPQ.top() : minPQ.top();
        }
        return minPQ.size() == 0 ? 0 : (minPQ.top() + maxPQ.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
