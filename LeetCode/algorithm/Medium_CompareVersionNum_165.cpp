class Solution {
public:
    int compareVersion(string version1, string version2) {
        int bigger = 0;
        int fInd = 0;
        int sInd = 0;
        int fLen = version1.size();
        int sLen = version2.size();
        int fNum = 0;
        int sNum = 0;
        
        while (fInd < fLen || sInd < sLen) {
            while (fInd < fLen && version1[fInd] != '.') {
                fNum *= 10;
                fNum += version1[fInd] - '0';
                fInd++;
            }
            while (sInd < sLen && version2[sInd] != '.') {
                sNum *= 10;
                sNum += version2[sInd] - '0';
                cout << sNum << endl;
                sInd++;
            }
            if (fNum > sNum) {
                return 1;
            } else if (fNum < sNum) {
                return -1;
            }
            fNum = sNum = 0;
            fInd++;
            sInd++;
        }
        return 0;
    }
};
