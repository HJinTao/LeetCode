#include<LeetCodeStructs.h>
class MinStack {
public:
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        minVal = min(val,minVal);
        st.push_back({val,minVal});
    }
    
    void pop() {
        st.pop_back();
        minVal = st.empty() ? INT_MAX : st.back().second;
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return minVal;
    }

private:
    vector<pair<int,int>> st;
    int minVal;
};