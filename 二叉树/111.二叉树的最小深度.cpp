#include<LeetCodeStructs.h>
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        else{
            int leftMin = root->left ? minDepth(root->left) : INT_MAX;
            int rightMin = root->right ? minDepth(root->right) : INT_MAX;
            return min(leftMin,rightMin) + 1;
        }
    }
};