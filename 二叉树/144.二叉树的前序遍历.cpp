#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return preorderIterator(root);
    }

    vector<int> preorderIterator(TreeNode* root){
        if(!root)   return {};

        stack<TreeNode*> st;
        TreeNode* node;
        vector<int> res;

        st.push(root);
        while(!st.empty()){
            node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right)  st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return res;
    }

    void preorderRecursion(TreeNode* node){
        if(!node)  return;
        res.push_back(node->val);
        preorderRecursion(node->left);
        preorderRecursion(node->right);
    }

private:
    vector<int> res;
};