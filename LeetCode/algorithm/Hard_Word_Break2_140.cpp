class Solution {
public:
    unordered_map<string, vector<string>> mem;
    unordered_set<string> dict;
    
    vector<string> recAdd(string s) {
        if (mem.find(s) != mem.end())
            return mem[s];
        vector<string> out;        
        if (dict.find(s) != dict.end()) {
            out.push_back(s);
        }
        
        for (int i = 1; i < s.size(); ++i) {
            string stSub = s.substr(i);
            if (dict.find(stSub) != dict.end()) {
                string rem = s.substr(0, i);
                vector<string> remOut = recAdd(rem);
                for (int j = 0; j < remOut.size(); ++j) {
                    out.push_back(remOut[j] + " " + stSub);
                }
            }
        }
        mem[s] = out;
        return out;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto each : wordDict) {
            dict.insert(each);
        }
        
        return recAdd(s);
    }
};
