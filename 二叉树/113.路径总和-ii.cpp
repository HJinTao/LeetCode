#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> res = {};
    vector<int> path = {};
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        travelPath(root,targetSum);
        return res;
    }

    void travelPath(TreeNode* root,int targetSum){
        if(!root){
            return;
        }
        targetSum -= root->val;
        path.emplace_back(root->val);
        if(!root->left && !root->right && !targetSum){
            res.emplace_back(path);
        }
        travelPath(root->left,targetSum);
        travelPath(root->right,targetSum);
        path.pop_back();
    }
};