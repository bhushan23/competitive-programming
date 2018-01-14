class Solution {
public:
    int findNthDigit(int n) {
        long long int base = 9;
        long long int digit = 1;
        while (n - base * digit > 0) {
            n = n - base * digit;
            base *= 10;
            digit++;
        }
        long long int num = pow(10, digit-1);
        int index = n % digit;
        num += n / digit;
        
        if (index == 0)
            num--;
        else {
            for (int i = index; i < digit; ++i) {
                num /= 10;
            }
        }
        return num % 10; 
    }
};
