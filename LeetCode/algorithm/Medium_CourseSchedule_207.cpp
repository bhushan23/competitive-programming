class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    unordered_set<int> nodes;

    void buildGraph(vector<pair<int, int>>& pr) {
        for (auto each : pr) {
            graph[each.first].push_back(each.second);
        }

        /*for (auto each : graph) {
            cout << each.first << ": ";
            for (auto each1 : graph[each.first]) {
                cout << each1 << " ";
            }
            cout << endl;
        }*/
    }

    bool topSort(int node) {

        if (visited.find(node) != visited.end() && nodes.find(node) == nodes.end())
            return false;
        visited.insert(node);
        // cout << "V:" << node << ":  ";
        for (auto each : graph[node]) {
            if (!topSort(each)) {
                // cout << each << " ";
                return false;
            }
        }
        // cout << endl;

        nodes.insert(node);
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.size()==0)
            return true;

        buildGraph(prerequisites);

        for (int i = 0; i < numCourses; ++i) {
            if (!topSort(i))
                return false;
        }
        return true;
    }
};
