class Solution {
public:
    unordered_map<string, bool> dictMap;
    unordered_map<string, bool> alreadyVisited;
    
    bool recBreak(string s) {
        for (int i = 0; i < s.length(); ++i) {
            string tmp = s.substr(0, i+1);
            if (dictMap.find(tmp) != dictMap.end()) {
                string nTmp = s.substr(i+1);
                bool rest = false;
                if (i+1 < s.length()) {
                    if (alreadyVisited.find(nTmp) != alreadyVisited.end()) {
                        if (alreadyVisited[nTmp] == true)
                            return true;
                        else 
                            continue;
                    } else if (recBreak(nTmp)) {
                        alreadyVisited[nTmp] = true;
                        return true;
                    } else {
                        continue;
                    }
                } else {
                    return true;
                }
            }
        }
        if (dictMap.find(s) != dictMap.end()) {
            alreadyVisited[s] = true;
            return true;
        }
        alreadyVisited[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int i = 0;
        int j = 1;
        
        for (auto d : wordDict) {
            dictMap[d] = true;
        }
        return recBreak(s);
    }
};
