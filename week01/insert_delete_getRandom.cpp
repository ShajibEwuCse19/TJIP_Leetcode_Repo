//TC: O(1)
//SC: O(2N)
class RandomizedSet {
public:
    vector<int>rSet; ///randmize Set
    unordered_map<int,int>idxMap;

    RandomizedSet() {
        rSet.clear();
    }
    
    bool insert(int val) {
        if(idxMap.count(val))return false; ///already present
        else ///new value
        {
            rSet.push_back(val); ///pushing the new item
            idxMap[val] = rSet.size() - 1; ///key = val, value = index

            return true;
        }
    }
    
    bool remove(int val) {
        if(!idxMap.count(val))return false; ///new value (not present)
        else
        {
            int tail = rSet.back(); ///taking last value
            rSet[idxMap[val]] = tail; ///taking tail to the position which we want to remove (we can use swap) 
            rSet.pop_back(); ///remove tail

            idxMap[tail] = idxMap[val]; /// update the map (position of val will be new position for tail)
            idxMap.erase(val); ///remove ta val

            return true;
        } 
    }
    
    int getRandom() {
        int ranIdx = rand() % rSet.size(); ///taking random index
        return rSet[ranIdx]; ///return random number
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
