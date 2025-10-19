#include<LeetCodeStructs.h>
class Solution {
public:
 
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        int res = 1;
        for(int x : s){
            if(!s.count(x - 1)){
                int len = 0;
                int next = x;
                while(s.count(next)){
                    len++;
                    next++;
                }
                res = max(len,res);
            }
        }
        return res;
    }
};