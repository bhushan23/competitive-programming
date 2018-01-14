class Solution {
public:
    int total;
    void recFind(vector<string> &o, int index, int curPos, int val) {
        if (index == total) {
            int hour = val >> 6;
            if (hour >= 12)
                return;
            int min = val & ((1 << 6) - 1);
            if (min >= 60)
                return;
            string hourSt = to_string(hour);
            string time = hourSt + (min / 10 == 0 ? ":0" : ":") + to_string(min);
            o.push_back(time);
            return;
        }
        index++;
        for (int i = curPos; i < 10; ++i) {
            int nval = val | (1<<i);
            recFind(o, index, i+1, nval);
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> out;
        total = num;
        recFind(out, 0, 0, 0);
        // sort(out.begin(), out.end());
        return out;
    }
};
