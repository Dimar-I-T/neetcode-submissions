class MyHashSet {
public:
    vector<vector<int>> buckets{10001};
    MyHashSet() {
        
    }

    int hashFunction(int key) {
        int sum = 0;
        string s = to_string(key);
        for (char c : s) {
            sum += c;
        }

        return sum % 10001;
    }

    void add(int key) {
        int index = hashFunction(key);
        vector<int>& bucket = buckets[index];
        auto itr = find(bucket.begin(), bucket.end(), key);
        if (itr == bucket.end()) {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        vector<int>& bucket = buckets[index];
        auto itr = find(bucket.begin(), bucket.end(), key);
        if (itr != bucket.end()) {
            buckets[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index = hashFunction(key);
        vector<int>& bucket = buckets[index];
        auto itr = find(bucket.begin(), bucket.end(), key);
        return (itr != bucket.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */