class MyHashMap {
public:
    vector<vector<pair<int, int>>> buckets{10001};
    MyHashMap() {
        
    }

    int hashFunction(int key) {
        string s = to_string(key);
        int sum = 0;
        for (char c : s) {
            sum += c;
        }

        return sum % 10001;
    }
    
    void put(int key, int value) {
        int index = hashFunction(key);
        vector<pair<int, int>>& bucket = buckets[index];
        bool ada = 0;
        for (pair<int, int>& p : bucket) {
            if (key == p.first) {
                p.second = value;
                ada = 1;
                break;
            }
        }

        if (!ada) {
            bucket.push_back({key, value});
        }
    }
    
    int get(int key) {
        int index = hashFunction(key);
        vector<pair<int, int>>& bucket = buckets[index];
        for (pair<int, int> p : bucket) {
            if (key == p.first) {
                return p.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        vector<pair<int, int>>& bucket = buckets[index];
        for (auto itr = bucket.begin(); itr != bucket.end(); ++itr) {
            if (key == itr->first) {
                bucket.erase(itr);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */