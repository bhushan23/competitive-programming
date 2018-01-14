class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 0)
            return true;
        
        bool CapMode = isupper(word[0]);
        if (word.size() == 1)
            return true;
        
        bool up = isupper(word[1]);
        if (CapMode == false && up == true)
            return false;
        
        CapMode = up;
        for (int i = 2; i < word.size(); ++i) {
            bool up = isupper(word[i]);
            if (CapMode != up)
                return false;
        }
        return true;
    }
};
