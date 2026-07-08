#include<LeetCodeStructs.h>
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<long long> dp(k + 1, 0);
        const int MOD = 1e9 + 7;
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = k; j >= 1; j--){
                dp[j] = (dp[j - 1] + (i - 1) * dp[j]) % MOD;
            }
            dp[0] = 0;
        }
        return dp[k];
    }
};