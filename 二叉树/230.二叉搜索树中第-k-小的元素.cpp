#include<LeetCodeStructs.h>
class Solution {
public:
    int res;
    int cnt;
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        inorderTraversal(root);
        return res;
    }
    
    void inorderTraversal(TreeNode* root){
        if(!root){
            return;
        }
        else{
            inorderTraversal(root->left);
            cnt--;
            if(!cnt){
                res = root->val;
            }
            inorderTraversal(root->right);
        }
    }
};