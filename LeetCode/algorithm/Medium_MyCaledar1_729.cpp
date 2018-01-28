bool compareFun(const pair<int, int> &a, int start) {
    return a.first < start;
}

class MyCalendar {
public:
    vector<pair<int, int>> time;
    MyCalendar() {
    }

    bool book(int start, int end) {
        if (time.size() == 0) {
            time.push_back({start, end});
            return true;
        }
        auto it = lower_bound(time.begin(), time.end(), start, compareFun);

        if (it > time.begin()) {
            if ((it-1)->second > start) {
                return false;
            }
        }
        if (it != time.end() && it->first < end) {
            return false;
        }
        time.insert(it, {start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
