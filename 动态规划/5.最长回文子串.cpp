#include<LeetCodeStructs.h>
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        vector<vector<bool>>dp(n,vector<bool>(n,true));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j - i >= 1){
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
                if(j - i + 1 > res.size() && dp[i][j]){
                    res = s.substr(i,j - i + 1);
                }
            }
        }
        return res;
    }
};