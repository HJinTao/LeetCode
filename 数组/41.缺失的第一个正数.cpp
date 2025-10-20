#include<LeetCodeStructs.h>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        nums.push_back(-1);   //针对1,2,3,4,...,n-1情形
        for(int i = 0; i < nums.size();i++){
            while(nums[i] >= 1 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i]){
                // 总共有两种情况,一种是nums[i]合法,一种是还未发生哈希冲突
                swap(nums[nums[i] - 1],nums[i]);
            }
        }
        int res = 1;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] != i + 1){
                res = i + 1;
                break;
            }
        }
        return res;
    }
};
// int firstMissingPositive(vector<int>& nums) {
//     unordered_set<int> s(nums.begin(),nums.end());
//     int res = 1;
//     while(s.find(res) != s.end()){
//         res++;
//     }
//     return res;
// }