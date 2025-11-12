#include<LeetCodeStructs.h>
class Solution {
public:
    vector<TreeNode*> linkNode;
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        preorderTravel(root);
        TreeNode* node = root;
        for(int i = 1; i < linkNode.size(); i++){
            node->right = linkNode[i];
            node->left = nullptr;
            node = node->right;
        }
    }

    void preorderTravel(TreeNode* root){
        if(!root){
            return;
        }
        linkNode.push_back(root);
        preorderTravel(root->left);
        preorderTravel(root->right);
    }
};