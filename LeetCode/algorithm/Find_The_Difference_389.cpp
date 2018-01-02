class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sM(26, 0);
        vector<int> tM(26, 0);
        
        for (int i = 0; i < s.length(); ++i) {
            sM[s[i]-'a']++;
        }
         for (int i = 0; i < t.length(); ++i) {
            tM[t[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (abs(sM[i] - tM[i]) > 0)  
                return i+'a';
        }
        assert(0 && "There must be atleast one different character");
    }
};
