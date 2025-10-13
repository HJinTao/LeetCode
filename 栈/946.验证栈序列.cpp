#include<LeetCodeStructs.h>
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        size_t i = 0;
        stack<int> st;
        for(int num : pushed){
            st.push(num);
            while(!st.empty() && st.top() == popped[i]){
                st.pop();
                i++;
            }
        }
        return i == popped.size();
    }
};

