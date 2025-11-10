#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return inorderIterate(root);
    }

    void inorderRecursion(TreeNode* node){
        if(!node)  return;
        inorderRecursion(node->left);
        res.push_back(node->val);
        inorderRecursion(node->right);
    }

    vector<int> inorderIterate(TreeNode* root){
        if(!root)  return {};
        
        stack<pair<TreeNode*,bool>> st;
        vector<int> res;
        TreeNode* node;
        bool visited;
        st.push(make_pair(root,false));
        while(!st.empty()){
            node = st.top().first;
            visited = st.top().second;
            if(visited){
                res.push_back(node->val);
                st.pop();
            }
            else{
                st.top().second = true;
                auto temp = st.top();
                st.pop();
                if(node->right)  st.push(make_pair(node->right,false));
                st.push(temp);
                if(node->left)  st.push(make_pair(node->left,false)); 
            }
        }
        return res;
    }

private:
    vector<int> res;
};