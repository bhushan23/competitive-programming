struct compareFun {
bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}
};

class MyCalendar {
public:
    set<pair<int, int>, compareFun> time;
    MyCalendar() {
    }

    bool book(int start, int end) {
        if (time.size() == 0) {
            time.insert({start, end});
            return true;
        }
        pair<int, int> b(0, start+1);
        auto it = time.lower_bound(b);

        if (it != time.end()) {
            if (it->first < end || it->second < start)
                return false;
        }
        auto pit = time.upper_bound(b);

        if (pit != time.end()) {
            if (pit->first < end || pit->second < start)
                return false;
        }

        time.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
