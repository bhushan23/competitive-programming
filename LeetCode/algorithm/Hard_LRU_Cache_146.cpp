class LRUCache {
public:
    list<pair<int, int>> use;
    unordered_map<int, list<pair<int, int>>::iterator> nodeMap;
    int capacity;
    int curSize;

    
    LRUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
    }

    int get(int key, int insertVal = false, int newVal = 0) {
         if (capacity == 0 || nodeMap.find(key) == nodeMap.end())
            return -1;
        list<pair<int, int>>::iterator nodeLoc = nodeMap[key];
        int val = (insertVal ? newVal : nodeLoc->second);
        use.erase(nodeLoc);
        use.push_back({key, val});
        nodeMap[key] = --(use.end());
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (get(key, true, value) != -1) {
            return;
        }
        if (curSize == capacity) {
            auto inValidated = use.front();
            nodeMap.erase(inValidated.first);
            use.pop_front(); 
        } else {
            curSize++;
        }
        use.push_back({key, value});
        nodeMap[key] = --(use.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
