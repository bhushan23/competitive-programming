class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int from = 0;
        int to = citations.size();
        int index = 0;
        
        if (to == 0)
            return 0;
        while (from <= to) {
            int mid = from + (to-from)/2;
            if (citations[citations.size() - mid - 1] > mid) {
                from = mid+1;
                index = from;
            } else {
                to = mid-1;                
            }
        }
        return index;
    }
};
