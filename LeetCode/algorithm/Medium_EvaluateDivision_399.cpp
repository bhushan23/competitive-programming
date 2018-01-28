class Solution {
public:

    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> visited;
    double solveEquation(const string &a, const string &b) {

        visited.insert(a);

        if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) {
            return -1.0;
        }

        if (a == b) {
            return 1.0;
        }

        if (graph[a].find(b) != graph[a].end()) {
            return graph[a][b];
        }
        for (auto adjNode : graph[a]) {
            double ans = -1;
            if (visited.find(adjNode.first) == visited.end())
                ans = solveEquation(adjNode.first, b);
            if (ans != -1.0) {
                return ans * adjNode.second;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); ++i) {
            pair<string, string> node = equations[i];
            graph[node.first][node.second] = values[i];
            graph[node.second][node.first] = 1/values[i];
        }

        vector<double> ans(queries.size(), 0);
        int i = 0;
        for (auto each : queries) {
            visited.clear();
            ans[i++] = solveEquation(each.first, each.second);
        }
        return ans;
    }
};
