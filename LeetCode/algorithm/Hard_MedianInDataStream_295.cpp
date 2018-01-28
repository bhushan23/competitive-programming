class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> set;
    multiset<int>::iterator lo, hi;

    MedianFinder() {
        lo = hi = set.begin();
    }


    void addNum(int num) {
        size_t size = set.size();
        set.insert(num);
        if (size == 0) {
            lo = hi = set.begin();
        } else {
            if (size & 1) {
                if (num < *lo) {
                    lo--;
                } else{
                    hi++;
                }
            } else {
                if (num < *lo) {
                    hi--;
                } else if (num >= *hi) {
                    lo++;
                } else {
                    lo++;
                    hi--;
                }
            }
        }
    }

    double findMedian() {
        return (float(*lo) + float(*hi)) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
