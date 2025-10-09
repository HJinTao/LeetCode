#include<LeetCodeStructs.h>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums[p0],nums[i]);
                p0++;
                if(p1 < p0){
                    p1 = p0;
                }
            }
            if(nums[i] == 1){
                swap(nums[p1],nums[i]);
                p1++;
            }
        }
    }

    // void sortColors(vector<int>& nums) {
    //     vector<int> count(3);
    //     for(auto i : nums){
    //         count[i]++;
    //     }
    //     int left = 0;
    //     int right = 0;
    //     for(int i = 0; i < 3; i++){
    //         right += count[i];
    //         for(int j = left; j < right; j++){
    //             nums[j] = i;
    //         }
    //         left = right;
    //     }
    // }
};

