#include<LeetCodeStructs.h>
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(const string& s : strs){
            int zero = 0,one = 0;
            for(const char& ch : s){
                if(ch == '0'){
                    zero++;
                }
                else{
                    one++;
                }
            }
            for(int i = m; i >= zero; i--){
                for(int j = n; j >= one; j--){
                    dp[i][j] = max(dp[i][j],dp[i - zero][j - one] + 1);  //非装满背包
                }
            }
        }
        return dp[m][n];
    }
};