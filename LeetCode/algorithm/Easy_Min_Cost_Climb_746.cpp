class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> step(cost.size() + 1,0);
        
        if (cost.size() == 1)
            return cost[0];
        step[0] = cost[0];
        step[1] = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            step[i] = cost[i] + min(step[i-1], step[i-2]);
        }
        step[cost.size()] = min(step[cost.size() - 1], step[cost.size() - 2]);
        return step[cost.size()];
    }
};
