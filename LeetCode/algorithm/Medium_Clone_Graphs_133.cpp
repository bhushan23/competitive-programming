/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> labelMap;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        UndirectedGraphNode *newNode = NULL;
        if (labelMap.find(node->label) == labelMap.end()) {
            newNode = new UndirectedGraphNode(node->label);
            labelMap[node->label] = newNode;
        } else {
            newNode = labelMap[node->label];
            return newNode;
        }
        for (auto each : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(each));
        }

        return newNode;
    }
};
