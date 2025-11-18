#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0);
        return res;
    }

    void backtracking(vector<int>& can,int tar,int index){
        if(tar == 0){
            res.push_back(path);
            return;
        }
        else if(index == can.size() || tar < 0){
            return;
        }
        else{
            for(int i = index; i < can.size(); i++){  
                if(i > index && can[i] == can[i - 1]){
                    continue;
                }
                if(i == can.size()){
                    return;
                }
                int num = can[i];
                path.push_back(num);
                backtracking(can,tar - num,i + 1);
                path.pop_back();
            }
    }
}
};