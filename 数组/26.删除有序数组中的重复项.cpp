#include<LeetCodeStructs.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        size_t slow = 0,fast = 0;
        while(fast < nums.size()){
            if(nums[fast] != nums[slow]){
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
};


