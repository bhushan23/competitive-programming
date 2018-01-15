#define isNum(x) ((x >= '0') && (x <= '9')) 

class Solution {
public:
    
    string decodeRec(string s, int &i) {
        string out;
        
        while (i < s.size() && s[i] != ']'){
            if (!isdigit(s[i])) {
                out += s[i++];
            } else {
                int n = 0;
                while (isNum(s[i])) {
                    n *= 10;
                    n += s[i++]-'0';
                }
                i++; // SKIP [ 
                string innerStr = decodeRec(s, i);
                i++; // SKIP ]
                
                while (n--) {
                    out += innerStr;
                }
            }
        }   
        return out;
    }
    string decodeString(string s) {
        int i = 0;
        return decodeRec(s, i);
    }
};
