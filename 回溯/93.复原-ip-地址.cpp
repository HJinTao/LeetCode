#include<LeetCodeStructs.h>
class Solution {
public:
    vector<string> res;
    vector<string> path;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0,4);
        return res;
    }
    void backtracking(const string& s,int start,int k){

        if(start == s.size()){
            if(k == 0){
                string ip = "";
                for(string code : path){
                    if(code[0] == '0' && code.size() > 1){
                        return;
                    }
                    ip += code;
                    ip.push_back('.');
                }
                ip.pop_back();
                res.push_back(ip);
            }
            else{
                return;
            }
        }
        else{
            bool curCheck = true;
            for(int end = start; end < s.size() && curCheck; end++){
                curCheck = check(s,start,end);
                if(curCheck){
                    path.emplace_back(s.substr(start,end - start + 1));
                    backtracking(s,end + 1,k - 1);
                    path.pop_back();
                }
            }
        }

    }

    long long string2num(const string& s,int start,int end){
        long long num = 0;
        for(int i = start; i <= end; i++){
            num = num * 10 + s[i] - '0';
        }
        return num;
    }

    bool check(const string& s,int start,int end){
        long long num = string2num(s,start,end);  
        return 0 <= num && num <= 255;
    }
};