class FreqStack {
public:
    int container[20001];
    unordered_map<int, int> um;
    int i = 0; 
    FreqStack() {
        um.reserve(20001);
    }
    
    void push(int val) {
        container[i] = val;
        um[val]++;
        i++;
    }

    void removeV(int idx) {
        for (int x = idx; x < i - 1; x++) {
            container[x] = container[x + 1];
        }
    }
    
    int pop() {
        int freq = 0;
        int res = 0;
        int idx = 0;
        for (int x = i - 1; x >= 0; x--) {
            int curr = container[x];
            int freqCurr = um[curr];
            if (freq < freqCurr) {
                freq = freqCurr;
                res = curr;
                idx = x;
            }
        }

        um[res]--;
        removeV(idx);
        i--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */