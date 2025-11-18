#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return res;
    }

    void backtracking(int k,int n,int start){
        if(n == 0 && k == 0){
            res.push_back(path);
            return;
        }
        else if(start > n){  //第三个分支相当于一个条件判断,取反即可,我也不知道我怎么想出来的,反正一遍就过了
            return;
        }
        else{
            for(int i = start; i <= min(n,9); i++){
                path.push_back(i);
                backtracking(k - 1,n - i,i + 1);
                path.pop_back();
            }
        }
    }
    
};