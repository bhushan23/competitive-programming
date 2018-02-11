class Solution {
public:
    stack<string> out;
    void addString(string &path, int start, int len) {
        string temp = path.substr(start, len);
        if (temp.size() > 0) {
            if (temp == ".") {
                return;
            } else if (temp == "..") {
                if (!out.empty())
                    out.pop();
            } else {
                out.push(temp);
            }
        }
    }
    string simplifyPath(string path) {

        int start = 1;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                addString(path, start, i-start);
                start = i + 1;
            }
        }
        addString(path, start, path.size()-start);
        string ans = "/";
        stack<string> tmp;
        while (!out.empty()) {
            tmp.push(out.top());
            out.pop();
        }

        while(!tmp.empty()) {
            ans += tmp.top();
            tmp.pop();
            if (!tmp.empty())
                ans += "/";
        }
        return ans;
    }
};
