#define BITSIZE 8
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int totalBytes = 0;
        
        for (auto each : data) {
            bitset<BITSIZE> bits = each;
            
            if (totalBytes < 1) {
                int index = BITSIZE-1;
                
                while (index >= 0 && bits.test(index))
                    index--;            
                totalBytes = BITSIZE-index-2;
                
                if (totalBytes == 0 || totalBytes >= 4)
                    return false;
            } else {
                if (totalBytes > 0 && bits.test(BITSIZE-1) == 1 && bits.test(BITSIZE-2) == 0)
                    totalBytes--;
                else 
                    return false;
            }
        }
        return (totalBytes < 1);
    }
};
