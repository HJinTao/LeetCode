#include<LeetCodeStructs.h>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> mp;   // <preSum,count>
        for(int i = 0; i < nums.size(); i++){
            if(i > 0){
                nums[i] += nums[i - 1];
            }
            if(mp.find(nums[i] - k) != mp.end()){
                res += mp[nums[i] - k];
            }
            if(nums[i] == k){     //这是因为sum([i,j])是分段函数,i = 0 与 i > 0 的情况不一致
                res++; 
            }
            mp[nums[i]]++;
        }
        return res;
    }
};