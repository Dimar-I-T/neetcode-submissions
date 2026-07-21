class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int res = 0;
        while (!q1.empty()) {
            res = q1.front();
            q2.push(res);
            q1.pop();
        }

        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }

        q2.pop();
        return res;
    }
    
    int top() {
        int res = 0;
        while (!q1.empty()) {
            res = q1.front();
            q2.push(res);
            q1.pop();
        }

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return res;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */