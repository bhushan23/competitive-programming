class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fp, sp;
        int len = nums.size();
        fp = sp = 0;

        while (fp < len && nums[fp] != val) {
            fp++;
        }
        sp = fp+1;
        while (sp < len) {
            if (nums[sp] == val) {
                sp++;
            } else {
                nums[fp++] = nums[sp++];
            }
        }
        return fp;
    }
};
