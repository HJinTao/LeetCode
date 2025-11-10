#include<LeetCodeStructs.h>
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return iterator(root);
    }
    
    bool fun(TreeNode* n1,TreeNode* n2){
        if(!n1 || !n2){
            return n1 == n2;
        }
        else{
            if(n1->val != n2->val){
                return false;
            }
            else{
                return fun(n1->left,n2->right) && fun(n1->right,n2->left);
            }
        }
        
    }

    // 层次遍历法迭代
    bool iterator(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curLevelSize = q.size();
            vector<int> curLevelNum(curLevelSize);
            for(int i = 0;i < curLevelSize;i++){
                TreeNode* node = q.front();
                curLevelNum[i] = node ? node->val : INT_MAX;
                q.pop();
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            int i = 0;
            int j = curLevelSize - 1;
            while(i <= j){
                if(curLevelNum[i++] != curLevelNum[j--]){
                    return false;
                }
            }
        }
        return true;
    }
};