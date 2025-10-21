#include<LeetCodeStructs.h>
#define rHash hash(s[right])
#define lHash hash(s[left])
class Solution {
public:

    int need[52] = {0};
    bool match[52] = {0};
    int hash(char ch){
        return 'a' <= ch && ch <= 'z' ? ch - 'a' : ch - 'A' + 26;
    }
    string minWindow(string s,string t){
        int n = s.size();
        int m = t.size();
        if(n < m)   return "";
        int required = 0;
        int formed = 0;
        for(int i = 0; i < m; i++){
            int index = hash(t[i]);
            if(need[index] == 0) required++;
            need[index]++;
            match[index] = true;
        }
        int left = 0;
        int len = INT_MAX;
        int start = 0;
        for(int right = 0; right < n; right++){
            if(match[rHash]){
                need[rHash]--;
                if(need[rHash] == 0) formed++;
            }
            while(formed == required){
                if(right - left + 1 < len){
                    start = left;
                    len = right - left + 1;
                }
                if(match[lHash]){
                    need[lHash]++;
                    if(need[lHash] > 0) formed--;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};