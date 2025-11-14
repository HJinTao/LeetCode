#include<LeetCodeStructs.h>
class Solution {
public:
    TreeNode* res = nullptr;
    int pVal;
    int qVal;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q){
            return root;
        }
        else{
            TreeNode* l = lowestCommonAncestor(root->left,p,q);
            TreeNode* r = lowestCommonAncestor(root->right,p,q);
            if(l && r){
                return root;
            }
            return l ? l : r;
        }
    }
    
    // 通俗易懂写法
    TreeNode* lowestCommonAncestorLower(TreeNode* root, TreeNode* p, TreeNode* q) {
        pVal = p->val;
        qVal = q->val;
        dfs(root);
        return res;
    }
    bool dfs(TreeNode* root){
        if(!root){
            return false;
        }
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        bool ret = root->val == pVal || root->val == qVal;
        if(l + r + ret >= 2 && !res){
            res = root;
        }
        ret |= l || r;
        return ret;
    }
};