#include<LeetCodeStructs.h>
class Solution {
public:

    long long pre = -2147483648 - 1;   
    // 搜索二叉树中序遍历有序
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        else{
            bool l = isValidBST(root->left);
            bool mid = root->val > pre;
            pre = root->val;
            bool r = isValidBST (root->right);
            return mid && l && r;
        }
    }
    
};