#include<LeetCodeStructs.h>
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        else if(!root->left && !root->right){
            return !(targetSum - root->val);
        }
        else{
            bool LCheck = hasPathSum(root->left,targetSum - root->val);
            bool RCheck = hasPathSum(root->right,targetSum - root->val);
            return LCheck || RCheck;
        }
    }
};