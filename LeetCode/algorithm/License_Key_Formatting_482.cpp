class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int cCount = S.length() - count(S.begin(), S.end(), '-');
        int newDash = cCount / K + (cCount % K == 0 ? 0: 1) - 1;
        int nLen = cCount+newDash;
        if (nLen <= 0)
            return "";
        string out(nLen, '-');
        
        int tK = 0;
        for (int i = S.length() - 1, j = cCount + newDash - 1; i >= 0; i--) {
            if (S[i] == '-')
                continue;
            out[j--] = toupper(S[i]);
            tK++;
            if (tK == K) {
                tK = 0;
                j--;
            }
        }
        return out;
    }
};
