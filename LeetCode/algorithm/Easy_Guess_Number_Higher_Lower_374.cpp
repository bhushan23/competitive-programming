// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int r, g;
        long long int lo, hi;
        lo = 0;
        hi = n;
        while(lo < hi) {
            r = (hi + lo) / 2;
            if (r < lo)
                continue;
            
            g = guess(r);
            if (g == 0)
                return r;
            if (g == 1) {
                lo = r+1;
            } else if (g == -1) {
                hi = r-1;
            }
        }
        return lo;
    }
};
