#include<LeetCodeStructs.h>
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()){
            return nullptr;
        }
        else{
            int rootValue = postorder.back();
            int index = find(inorder.begin(),inorder.end(),rootValue) - inorder.begin();
            vector<int> IL(inorder.begin(),inorder.begin() + index);
            vector<int> IR(inorder.begin() + index + 1,inorder.end());
            vector<int> PL(postorder.begin(),postorder.begin() + index);
            vector<int> PR(postorder.begin() + index,postorder.end() - 1);
            TreeNode* root = new TreeNode(rootValue);
            root->left = buildTree(IL,PL);
            root->right = buildTree(IR,PR);
            return root;
        }
    }
};