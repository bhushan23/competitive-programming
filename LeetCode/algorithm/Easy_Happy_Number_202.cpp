class Solution {
public:

    int computeSum(int n) {
        int sum = 0;
        while (n) {
            int k = n%10;
            sum += k * k;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> log;
        log.insert(n);
        do {
            n = computeSum(n);
            if (n == 1) {
                return true;
            } else if (log.find(n) != log.end())
                return false;
            log.insert(n);
        } while(true);
    }
};
