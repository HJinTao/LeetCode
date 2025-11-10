#include<LeetCodeStructs.h>
class Solution {
public:
    int res = -1;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return res;
    }

    int depth(TreeNode* node){
        //获取以当前node为root的子树的深度depth
        if(!node){
            return -1;
        }
        else{
            int leftDepth = depth(node->left);
            int rightDepth = depth(node->right);
            res = max(leftDepth + rightDepth + 2,res);
            return max(leftDepth,rightDepth) + 1;
        }
    }
};