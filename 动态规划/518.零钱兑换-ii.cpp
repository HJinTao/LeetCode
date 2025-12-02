#include<LeetCodeStructs.h>
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1,0);
        dp[0] = 1;
        for(const int& coin : coins){
            for(int l = coin; l <= amount; l++){
                dp[l] += dp[l - coin];
            }
        }
        return dp[amount];
    }
};