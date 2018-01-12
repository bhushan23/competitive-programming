class Solution {
public:   
    
    int lengthLongestPath(string input) {
        int ans = 0;
        input += "\n";
        int len = input.length();
        size_t n = count(input.begin(), input.end(), '\n');
        vector<int> levelWise(n, 0);
        int level = 0;
        int bLen = 0;
        bool fileFound = false;
        
        for (int i = 0; i < len; ++i) {
           switch(input[i]) {
               case '\n':
                   if (fileFound) {
                       ans = max(ans, accumulate(levelWise.begin(), levelWise.begin() + level+1, 0) + level);
                       fileFound = false;
                   }
                   level = 0;
                   bLen = 0;
                   break;
               case '\t':
                   level++;
                   break;
               case '.':
                   fileFound = true;
               default:
                   bLen++;
                   levelWise[level] = bLen;
                   break;
           }
        }
        
        return ans;
    }
};
