#include<LeetCodeStructs.h>
class Solution {
public:
    int countNodes(TreeNode* root) {
        return countNodesBetter(root);
    }
    
    int countNodeCommon(TreeNode* root){
        if(!root){
            return 0;
        }
        else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        } 
    }

    //抓住完全二叉树 任意根节点的左右子树中至少有一个是Perfect Tree 的特点进行剪枝 时间复杂度O(log^2)
    int countNodesBetter(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftDepth = 0;
        int rightDepth = 0;
        TreeNode* node = root->left;
        while(node){
            node = node->left;
            leftDepth++;    
        }
        node = root->right;
        while(node){
            node = node->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth){
            return (2 << leftDepth) - 1;
        }
        else{
            return countNodesBetter(root->left) + countNodesBetter(root->right) + 1;
        }
    }
};