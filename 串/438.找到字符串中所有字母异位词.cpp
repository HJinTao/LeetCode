#include<LeetCodeStructs.h>
#define lHash s[left] - 'a'
#define rHash s[right] - 'a'
class Solution {
public:
    vector<int> findAnagrams(string s, string p){
        int n = s.size();
        int m = p.size();
        if(n < m) return {};
        
        vector<int> res;
        int need[26] = {0};
        int formed = 0;
        int required = 0;
        for(int i = 0; i < m; i++){
            if(need[p[i] - 'a']++ == 0) required++;
        }
        for(int i = 0; i < m; i++){
            if(--need[s[i] - 'a'] == 0) formed++;
        }
        if(required == formed) res.push_back(0);
        int right;
        for(int left = 0; left < n - m; left++){ // (left,right]
            right = left + m;
            if(need[lHash]++ == 0) formed--;
            if(--need[rHash] == 0) formed++;
            if(formed == required){
                res.push_back(left + 1);
            }
        }
        return res;
    }
};
// vector<int> findAnagrams(string s, string p) {
//     int left = 0;
//     int right = 0;
//     int len1 = s.size();
//     int len2 = p.size();
//     vector<int> hashTemplate(26,0);
//     for(char c : p){
//         hashTemplate[c - 'a']++;
//     }
//     vector<int> res;
//     for(;left <= len1 - len2; left++){
//         right = left;
//         vector<int> hash = hashTemplate;
//         while(right < left + len2 && hash[s[right] - 'a'] > 0){
//             hash[s[right] - 'a']--;
//             right++;
//         }
//         if(right - left == len2){
//             res.push_back(left);
//         }
//     }
//     return res;
// }