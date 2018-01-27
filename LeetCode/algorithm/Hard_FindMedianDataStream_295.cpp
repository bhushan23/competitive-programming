class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

    MedianFinder() {

    }

    void balance() {
        if (maxQ.size() > minQ.size()+1) {
            int el = maxQ.top();
            maxQ.pop();
            minQ.push(el);
        }
    }
    void addNum(int num) {
        maxQ.push(num);

        balance();
        while (maxQ.size() > 0 && minQ.size() > 0 && maxQ.top() > minQ.top()) {
            maxQ.push(minQ.top());
            minQ.pop();
            balance();
        }
    }

    double findMedian() {
        if (maxQ.size() == minQ.size()) {
            return (float(maxQ.top()) + float(minQ.top())) / 2;
        }
        return maxQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
