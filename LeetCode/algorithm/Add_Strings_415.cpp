class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans(max(num1.length(), num2.length()), '0');
        int i, carry = 0;
        for (i = 0; i < min(num1.length(), num2.length()); ++i) {
            int tmp = carry + num1[i] - '0' + num2[i] - '0';
            ans[i] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        
        for (; i < num1.length(); ++i) {
            int tmp = carry + num1[i] - '0';
            ans[i] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        
        for (; i < num2.length(); ++i) {
            int tmp = carry + num2[i] - '0';
            ans[i] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        if (carry) {
            ans.resize(ans.size()+1, carry+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
