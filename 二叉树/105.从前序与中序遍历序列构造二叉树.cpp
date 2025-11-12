#include<LeetCodeStructs.h>
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return nullptr;
        }
        else{
            int rootVal = preorder[0];
            TreeNode* root = new TreeNode(rootVal);
            int index = find(inorder.begin(),inorder.end(),rootVal) - inorder.begin();
            vector<int> IL(inorder.begin(),inorder.begin() + index);
            vector<int> IR(inorder.begin() + index + 1,inorder.end());
            vector<int> PL(preorder.begin() + 1,preorder.begin() + IL.size() + 1);
            vector<int> PR(preorder.begin() + IL.size() + 1,preorder.end());
            root->left = buildTree(PL,IL);
            root->right = buildTree(PR,IR);
            return root;
        }
    }
};