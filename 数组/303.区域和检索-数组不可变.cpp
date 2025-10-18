#include<LeetCodeStructs.h>
class NumArray {
public:
    NumArray(vector<int>& nums) {
        preSum = vector<int>(nums.size());
        preSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return preSum[right];
        }
        else{
            return preSum[right] - preSum[left - 1];    
        }
    }
private:
    vector<int> preSum;
};