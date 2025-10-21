#include<LeetCodeStructs.h>
class Solution {
public:
    int hash[26] = {0}; 
    vector<int> findAnagrams(string s, string p){
        vector<int> res;
        int n = s.size();
        int m = p.size();
        if(n < m){
            return {};
        }
        for(int i = 0; i < m; i++){
            hash[s[i] - 'a']++;
            hash[p[i] - 'a']--;
        }
        if(isAllZero()){
            res.push_back(0);
        }
        int left = 0;
        int right;
        for(int left = 0; left < n - m; left++){ // (left,right]
            right = left + m;
            hash[s[left] - 'a']--;
            hash[s[right] - 'a']++;
            if(isAllZero()){
                res.push_back(left + 1);
            }
        }
        return res;
    }

    bool isAllZero(){
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0)
                return false;
        }
        return true;
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