#include<LeetCodeStructs.h>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.size() == 0){
                    return false;
                }
                char match = st.top();
                if(ch == ')' && match == '('
                || ch == '}' && match == '{'
                || ch == ']' && match == '['
                ){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.size() == 0 ? true : false;
    }
};

