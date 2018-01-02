#define isNum(x) ((x >= '0') && (x <= '9')) 

class Solution {
public:
    
    int readNum(string s, int &i) {
        int ans = 0;
        int index = 0;
        while(i < s.length() && isNum(s[i])) {
            ans *= 10;
            ans += s[i] - '0';
            i++;
        }
        //cout << "Num: " << ans << "\n";
        return ans;
    }
    string decodeString(string s) {
        size_t index = 0;
        size_t nextIndex = 0;
        int num;
        
        stack<string> stStr;
        stack<int> stNum;
        
        for (int i = 0; i < s.length();) {
            if (isNum(s[i])) {
                if (index < i) {
                    string sStr = s.substr(index, i-index);
                    //cout << "Pushing " << sStr << "\n";
                    stStr.push(sStr);
                }
                num = readNum(s, i);
                stNum.push(num);
            } else if (s[i] == '[') {
                stStr.push("[");
                index = i+1;
                i++;
            } else if (s[i] == ']') {
                string sStr = s.substr(index, i-index);
                //cout << "sStr: " << sStr << "\n";
                string nStr;
                stack<string> tStack;
                while (!stStr.empty() && stStr.top() != "[") {
                    tStack.push(stStr.top());
                    //cout << "Poping " << stStr.top() << "\n";
                    stStr.pop();
                }
                stStr.pop();
                while(!tStack.empty()) {
                    nStr += tStack.top();
                    tStack.pop();
                }
                num = stNum.top();
                stNum.pop();
                sStr = nStr + sStr;
                //cout << sStr << " " << num << " \n";
                string ans;
                while (num--) {
                    ans += sStr;
                }
                //cout << "Pushing " << ans << "\n";
                stStr.push(ans);
                index = i+1;
                i++;
            } else {
                i++;
            }
        }
        if (index < s.length()) {
            string sStr = s.substr(index, s.length()-index);
            //cout << "Pushing " << sStr << "\n";
            stStr.push(sStr);
        }
        stack<string> tStack;
        string nStr;
        while (!stStr.empty()) {
            if (stStr.top() != "[")
                tStack.push(stStr.top());
            stStr.pop();
        }
        while(!tStack.empty()) {
            nStr += tStack.top();
            tStack.pop();
        }
        return nStr;
    }
};
