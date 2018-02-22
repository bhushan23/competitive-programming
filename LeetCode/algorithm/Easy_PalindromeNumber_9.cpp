class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        int dig = 0;
        if (num < 0)
            return false;
        if (num <= 9)
            return true;
        while (num) {
            dig++;
            num /= 10;
        }
        int i = 1;
        // cout << dig << endl;
        dig--;
        while (i <= dig) {
            int upper = (int)(x / pow(10, dig)) % (int)(pow(10, i));
            int lower = x % 10;
            // cout << upper << " " << lower << endl;
            if (upper != lower)
                return false;
            x /= 10;
            dig-=2;
        }
        return true;
    }
};
