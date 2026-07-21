class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        int left = (!st.empty()) ? st.top().second : INT_MAX;
        int minn = min(left, val);
        st.push({val, minn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
