#include<LeetCodeStructs.h>
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1; i * i <= n; i++){
            nums.push_back(i * i);
        }
        vector<int> dp(n + 1,n + 1);
        dp[0] = 0;
        for(const int& num : nums){
            for(int l = num; l <= n; l++){
                dp[l] = min(dp[l - num] + 1,dp[l]);
            }
        }
        return dp[n];
    }
};