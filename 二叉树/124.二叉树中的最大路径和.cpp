#include<LeetCodeStructs.h>
class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        fun(root);
        return res;
    }

    int fun(TreeNode* root){
        if(!root){
            return 0;
        }
        else{
            int l = max(fun(root->left),0);
            int r = max(fun(root->right),0);
            
            int ret = max(l,r) + root->val;
            int newRes = root->val + l + r;
            res = max(newRes,res);
            return ret;
        }
    }
};