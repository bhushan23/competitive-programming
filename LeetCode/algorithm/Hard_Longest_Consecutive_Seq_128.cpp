class Solution {
public:
    unordered_map<int, int> lMap;
    unordered_map<int, bool> visited;
    int maxE;

    int recVisit(int element) {
        
        if (visited.find(element) != visited.end())
            return lMap[element];
        
        visited[element] = true;
        if (lMap.find(element) != lMap.end()) {
            lMap[element] += recVisit(element-1); 
        } else {
            return 0;
        }
        return lMap[element];
    }
    int longestConsecutive(vector<int>& nums) {
        maxE = 0;
        for (auto each : nums) {
            lMap[each] = 1;
        }
        
        for (auto each : nums) {
            maxE = max(maxE, recVisit(each));
        }
        return maxE;
    }
};
