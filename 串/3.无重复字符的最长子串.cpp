#include<LeetCodeStructs.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        vector<int> hash(128,-1);  // <char,index>
        while(right < s.size()){
            while(right < s.size() && hash[s[right]] < left){
                hash[s[right]] = right;
                right++;
            }
            res = max(res,right - left);
            left = hash[s[right]] + 1;
        }
        return res;
    }
};