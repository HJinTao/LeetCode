#include<LeetCodeStructs.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
    }
};
// void rotate(vector<int>& nums, int k) {
//     int n = nums.size();
//     k %= n;
//     vector<int> res(n);
//     for(int i = 0; i < n; i++){
//         res[i] = i < k ? nums[n - k + i] : nums[i - k];
//     }
//     nums = res;
// }
