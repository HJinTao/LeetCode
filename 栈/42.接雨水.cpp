#include<LeetCodeStructs.h>
class Solution {
public:

    int trap(vector<int>& height){
        int left = 0;
        int right = height.size() - 1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int res = 0;
        while(left <= right){
            leftMax = max(height[left],leftMax);
            rightMax = max(height[right],rightMax);
            if(leftMax <= rightMax){
                res += leftMax - height[left];
                left++;
            }else{
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
};
// int trap(vector<int>& height) {
//     vector<int> left(height.size(),0);
//     vector<int> right(height.size(),0);
//     int m = INT_MIN;
//     for(int i = 0; i < height.size(); i++){
//         m = max(height[i],m);
//         left[i] = m;
//     }
//     m = INT_MIN;
//     for(int i = height.size() - 1; i >= 0; i--){
//         m = max(height[i],m);
//         right[i] = m;
//     }
//     int res = 0;
//     for(int i = 0; i < height.size(); i++){
//         res += min(left[i],right[i]) - height[i];
//     }
//     return res;
// }