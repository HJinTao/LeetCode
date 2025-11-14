#include<LeetCodeStructs.h>
class Solution {
public:
    //递归
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val){
            return root;
        }
        else{
            if(root->val < val){
                return searchBST(root->right,val);
            }
            else{
                return searchBST(root->left,val);
            }
        }
    }

    //迭代
    TreeNode* searchBST(TreeNode* root, int val){
        TreeNode* node = root;
        while(node){
            if(node->val < val){
                node = node->right;
            }
            else if(node->val > val){
                node = node->left;
            }
            else{
                break;
            }
        }
        return node;
    }
};