#include<LeetCodeStructs.h>
class Solution {
public:
    string path;
    vector<string> res;
    const vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7 <-- 注意：这里有4个字母
        "tuv",  // 8
        "wxyz"  // 9 <-- 注意：这里有4个字母        
    };

    vector<string> letterCombinations(string digits) {
        backtracking(digits,0);
        return res;
    }

    void backtracking(string &digits,int start){
        if(start == digits.size()){
            res.push_back(path);
            return;
        }
        else{
            int num = digits[start] - '0';
            for(char ch : mapping[num]){
                path.push_back(ch);
                backtracking(digits,start + 1);
                path.pop_back();
            }
        }
    }


};