#include<LeetCodeStructs.h>
class Solution {
public:
    int res;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dynamic(nums,target);
    }
    
    //等价为寻找子数组P
    int dynamic(vector<int>& nums, int tar){
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum + tar) % 2 || sum + tar <= 0){  //p是正整数时才有解
            return 0;
        }
        int p = (sum + tar) / 2;
        vector<int> dp(p + 1,0);
        dp[0] = 1;
        //dp[l]表示选到num时 和为l的子数组数
        for(const int& num : nums){
            for(int l = p; l >= num; l--){
                dp[l] += dp[l - num];   //装满背包
            }
        }
        return dp[p];
    }

    void dfs(const vector<int>& nums,int tar,int idx){
        if(idx == nums.size()){
            if(tar == 0){
                res++;
            }
            return;
        }
        else{
            dfs(nums,tar - nums[idx],idx + 1);
            dfs(nums,tar + nums[idx],idx + 1);
        }
    }
};