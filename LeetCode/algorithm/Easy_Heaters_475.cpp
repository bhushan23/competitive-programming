#define GETRAD(house, heater) (abs(houses[house] - heaters[heater]))
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> radius(heaters.size(), INT_MIN);
        int j = 0;
        int maxR = INT_MIN;
        
        for (int i = 0; i < houses.size(); ++i) {
            while (j < heaters.size() - 1 && GETRAD(i, j) >= GETRAD(i, j+1)) {
                j++;
            }
            radius[j] = max(radius[j], GETRAD(i, j));
        }
        for (auto each : radius) {
            maxR = max(maxR, each);
        }
        return maxR;        
    }
};
