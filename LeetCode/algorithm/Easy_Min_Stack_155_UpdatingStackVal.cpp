class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    int minEl;
    MinStack() {
        minEl = 10000;
    }
    
    void push(int x) {
        if (st.empty()) {
            minEl = x;
            st.push(x);
        } else {
            if (x >= minEl)
                st.push(x);
            else {
                st.push(2*x-minEl);
                minEl = x;
            }
        }
    }
    
    void pop() {
        if (!st.empty()) {
            int top = st.top();
            st.pop();
            if (top < minEl) {
                minEl = 2*minEl - top;
            }
        }
    }
    
    int top() {
        if (!st.empty()) {
            int top = st.top();
            if (top < minEl) {
                return 2*minEl - top;
            } else {
                return top;
            }
        }
    }
    
    int getMin() {
        return minEl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
