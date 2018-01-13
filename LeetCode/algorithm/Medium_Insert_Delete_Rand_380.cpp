static int kap = []() {
    std::ios::sync_with_stdio(false);
    return 0;
}();

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, bool> rMap;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (rMap.find(val) != rMap.end())
            return false;
        rMap[val] = true;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (rMap.find(val) == rMap.end())
            return false;
        rMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        auto random = next(rMap.begin(), rand()%rMap.size());
        return random->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
