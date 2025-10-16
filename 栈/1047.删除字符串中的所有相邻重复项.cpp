#include<LeetCodeStructs.h>
class Solution {
public:
    string removeDuplicates(string s){
        //string 可以封装成栈
        string res;
        for(char c : s){
            if(!res.empty() && res.back() == c){
                res.pop_back();
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }

};
// string removeDuplicates(string s) {
//     stack<char> st;
//     string res = "";     
//     for(char c : s){
//         if(st.empty() || st.top() != c){
//             st.push(c);
//         }
//         else{
//             st.pop();
//         }
//     }
//     while(!st.empty()){
//         res += st.top();
//         st.pop();
//     }
//     reverse(res.begin(),res.end());
//     return res;
// }