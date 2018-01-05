
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        string ans;
        if (numerator == 0)
            return "0";
        
        if (numerator < 0 ^ denominator < 0) 
            ans = "-";
        
        long long int num = abs((long long int) numerator);
        long long int denom = abs((long long int)denominator);
        long long int d = num / denom;
        long long int rem = num % denom;
        
        unordered_map<int, int> rMem;
        
        ans += to_string(d);
        if (rem == 0)
            return ans;
        
        ans += ".";
        
        while (rem != 0) {
            if (rMem.find(rem)  != rMem.end()) {
                ans.insert(rMem[rem], 1, '(');
                ans += ")";
                break;
            }
            
            rMem[rem] = ans.size();
            rem *= 10;
            d = rem / denom;
            ans += to_string(d);
            rem = rem % denom;
            
        }
        return ans;
    }
};
