#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)  return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int size = q.size();
            res.push_back(q.back()->val);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return res;

    }
};