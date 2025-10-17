#include<LeetCodeStructs.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = INT_MIN;
        while(left <= right){
            if(height[left] < height[right]){
                res = max(res,(right - left + 1) * height[left]);
                left++;
            }
            else{
                res = max(res,(right - left + 1) * height[right]);
                right--;
            }
        }
        return res;
    }
};