#include<LeetCodeStructs.h>
class Solution {
public:
    int res;
    int target;
    unordered_map<long long,int> prefixCnt;   // <prefixSum,cnt> 

    //O(N) 前缀和解法 可以类比560问题
    int pathSumON(TreeNode* root,long long curPrefix) {
        if(!root){
            return 0;
        }
        curPrefix += root->val;
        int ret = prefixCnt[curPrefix - target];
        prefixCnt[curPrefix]++;
        ret += pathSumON(root->left,curPrefix) + pathSumON(root->right,curPrefix);  //注意这里!
        prefixCnt[curPrefix]--;
        return ret;
    }


    int pathSum(TreeNode* root, int targetSum) {
        prefixCnt[0] = 1;   //定义S_0 = 0 避免分段处理
        target = targetSum;
        return pathSumON(root,0);
    }
    
    void fun(TreeNode* root, long long targetSum){
        if(!root){
            return;
        }
        targetSum -= root->val;
        if(!targetSum){
            res++;
        }
        fun(root->left,targetSum);
        fun(root->right,targetSum);
    }

    void traversal(TreeNode* root){
        if(!root){
            return;
        }
        fun(root,target);
        traversal(root->left);
        traversal(root->right);
    }
};