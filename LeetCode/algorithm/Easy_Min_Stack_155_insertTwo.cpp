class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    double minEl;
    MinStack() {
        minEl = 10000;
    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            st.push(x);
        } else {
            int top = st.top();
            st.pop();
            int min = st.top();
            st.push(top);
            if (x < min) {
                st.push(x);
            } else {
                st.push(min);
            }
            st.push(x);
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
            st.pop();
        }
    }
    
    int top() {
        if (!st.empty()) {
            return st.top();
        }
    }
    
    int getMin() {
        int top = st.top();
        st.pop();
        int min = st.top();
        st.push(top);
        return min;
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
