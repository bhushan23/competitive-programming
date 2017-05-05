class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string cPat;
        istringstream iss(str);
        map<char, string> mapping;
        map<char, string>::iterator it;
        set<string> exists;
        int i = 0;
        while(getline(iss, cPat, ' ') || i < pattern.length()) {
            it = mapping.find(pattern[i]);
            if (it != mapping.end() && cPat.compare(it->second) != 0) {
                return false;
            } else {
                if (it == mapping.end() && exists.find(cPat) != exists.end()) {
                        return false;
                } else {
                        mapping[pattern[i]] = cPat;
                        exists.insert(cPat);
                }
            }    
        i++;
        }
        return (i == pattern.length());
    }
};
