#include<LeetCodeStructs.h>
class Solution {
public:
    string decodeString(string s){
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        string sub = "";
        for(size_t i = 0; i < s.size(); i++){  
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            else if(isalpha(s[i])){
                sub += s[i];     //字符串拼接用+=
            }
            else if(s[i] == '['){
                strs.push(sub);
                nums.push(num);
                num = 0;
                sub = "";
            }
            else{
                int ct = nums.top();
                nums.pop();
                while(ct--){
                    strs.top() += sub;
                }
                sub = strs.top();
                strs.pop();
            }
        }
        return sub;

    }
};
    //笨蛋写法
    // string decodeString(string s) {
    //     stack<int> nums;
    //     stack<string> chars;
    //     for(auto ch : s){
    //         if(isNum(ch)){
    //             nums.push(ch - '0');
    //         }
    //         else if(isChar(ch)){
    //             chars.push(string(1,ch));
    //         }
    //         else{
    //             if(ch == '['){
    //                 chars.push(string(1,ch));
    //                 nums.push(-1);
    //             }
    //             else{
    //                 string sub;
    //                 string pat;
    //                 while(chars.top() != "["){
    //                     if(chars.top().size() > 1){
    //                         reverse(chars.top().begin(),chars.top().end());
    //                     }
    //                     sub += chars.top();
    //                     chars.pop();
    //                 }
    //                 chars.pop();
    //                 reverse(sub.begin(),sub.end());

    //                 nums.pop();
    //                 int index = 0;
    //                 int count = 0;
    //                 while(!nums.empty() && nums.top() != -1){
    //                     count += nums.top() * pow(10,index);
    //                     index++;
    //                     nums.pop();
    //                 }

    //                 for(int i = 0; i < count; i++){
    //                     pat += sub;
    //                 }
    //                 chars.push(pat);
                    
    //             }
    //         }
    //     }
    //     string res;
    //     while(!chars.empty()){
    //         res.insert(0,chars.top());
    //         chars.pop();
    //     }
    //     return res;

    // }     
    
    // bool isNum(char ch){
    //     return '0' <= ch && ch <= '9';
    // }

    // bool isChar(char ch){
    //     return 'a' <= ch && ch <= 'z';
    // }

