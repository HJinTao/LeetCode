#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }

    void backtracking(int n,int k,int start){
        if(k == 0){
            res.push_back(path);
            return;
        }
        else{
            for(int i = start; i <= n - k + 1; i++){
                path.push_back(i);
                backtracking(n,k - 1,i + 1);
                path.pop_back();
            }
        }
    }
};