#include<LeetCodeStructs.h>
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(0,nums.size() - 1,nums);
    }

    TreeNode* fun(int l,int r,vector<int>& nums){
        if(l > r){
            return nullptr;
        }
        else{
            int index = l + (r - l) / 2;
            TreeNode* root = new TreeNode(nums[index]);
            root->left = fun(l,index - 1,nums);
            root->right = fun(index + 1,r,nums);
            return root;
        }
    }
};