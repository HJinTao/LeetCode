#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return res;
    }

    void backtracking(string &s,int start){
        if(start == s.size()){
            res.emplace_back(path);
            return;
        }
        else{
            for(int end = start; end < s.size(); end++){
                if(check(s,start,end)){
                    path.emplace_back(s.substr(start,end - start + 1));
                    backtracking(s,end + 1);
                    path.pop_back();
                }
            }
        }
    }

    //[start,end]
    bool check(const string &s,int start,int end){ 
        int i = start,j = end;
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
};