#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return postorderIterator(root);
    }

    vector<int> postorderIterator(TreeNode* root){
        if(!root)   return {};

        stack<pair<TreeNode*,bool>> st;   // st的bool值代表着这个节点是否可以被收割,或者说这个节点是否已经展开,若已经展开了则可以收割
        TreeNode* node;
        vector<int> res;

        st.push(make_pair(root,false));
        while(!st.empty()){
            node = st.top().first;
            bool visited = st.top().second;
            if(visited){
                res.push_back(node->val);
                st.pop();
            }
            else{
                st.top().second = true;
                if(node->right)  st.push(make_pair(node->right,false));
                if(node->left)  st.push(make_pair(node->left,false)); 
            }
        }
        return res;
    }

    void postorderRecursion(TreeNode* node){
        if(!node)  return;
        postorderRecursion(node->left);
        postorderRecursion(node->right);
        res.push_back(node->val);
    }

private:
    vector<int> res;
};