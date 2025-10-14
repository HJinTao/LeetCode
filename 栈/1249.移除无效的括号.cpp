#include<LeetCodeStructs.h>
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(res.size());
                res.push_back(s[i]);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                    res.push_back(s[i]);
                }
                else{
                    continue;
                }
            }
            else{
                res.push_back(s[i]);
            }
        }

        while(!st.empty()){
            res.erase(res.begin() + st.top());
            st.pop();
        }
        return res;
    }
};