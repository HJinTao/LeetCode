#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int record[26] = {0};
        int n = s.size();
        vector<int> res;
        //不需要用rfind,可以用一个哈希数组来记录每个字符最后出现的索引
        for(int i = 0; i < n;i++){
            int key = s[i] - 'a';
            record[key] = i;
        }
        int left = 0,right = INT_MIN;
        for(int i = 0; i < n; i++){
            int key = s[i] - 'a';
            right = max(right,record[key]);
            if(i == right){
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};  