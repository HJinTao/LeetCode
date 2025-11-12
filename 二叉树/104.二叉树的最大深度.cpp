#include<LeetCodeStructs.h>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        else{
            int LMax = root->left ? maxDepth(root->left) : INT_MIN;
            int RMax = root->right ? maxDepth(root->right) : INT_MIN;
            return max(LMax,RMax) + 1;
        }
    }
};