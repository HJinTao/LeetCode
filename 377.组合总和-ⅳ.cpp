#include<LeetCodeStructs.h>
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1,0);
        dp[0] = 1;
        //颠倒完全背包的遍历顺序
        for(int l = 1; l <= target; l++){
            for(const int& num : nums){
                if(l >= num){
                    dp[l] += dp[l - num];
                }
            }
        }
        return dp[target];
    }
};