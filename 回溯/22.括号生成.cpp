#include<LeetCodeStructs.h>
class Solution {
public:
    string path;
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s;
        for(int i = 0; i < n; i++){
            s += "()";
        }
        vector<int> used(2 * n,0);
        backtracking(used,s);
        return res;
    }

    void backtracking(vector<int>& used,string& s){
        if(path.size() == s.size() && check(path)){
            res.push_back(path);
            return;
        }
        else{
            vector<int> hash(2,0);
            for(int i = 0; i < s.size();i++){
                int key = s[i] - '(';
                if(!used[i] && !hash[key]){
                    hash[key] = 1;
                    used[i] = 1;
                    path.push_back(s[i]);
                    backtracking(used,s);
                    path.pop_back();
                    used[i] = 0;
                }
            }
        }
    }
    

    bool check(string& s){
        stack<char> st;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};