#include<LeetCodeStructs.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int ch[26] = {0};
        for(int i = 0; i < s.size(); i++){
            ch[s[i] - 'a']++;
            ch[t[i] - 'a']--;
        }
        for(int i : ch){
            if(i){
                return false;
            }
        }
        return true;
    }
};