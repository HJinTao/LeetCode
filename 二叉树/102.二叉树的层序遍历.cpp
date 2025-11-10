#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curLevelSize = q.size();
            vector<int> curLevelVal(curLevelSize);
            for(int i = 0; i < curLevelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                curLevelVal[i] = node->val;
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            res.push_back(curLevelVal);
        }
        return res;
    }
};