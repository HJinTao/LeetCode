#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return res;
    }


    void backtracking(vector<int>& can,int tar,int index){
        if(tar < 0){
            return;
        }
        else if(tar == 0){
            res.push_back(path);
            return;
        }   
        else{
            for(int i = index; i < can.size(); i++){   //注意index保证了path有序唯一,若不有序则存在重复path
                int num = can[i];
                path.push_back(num);
                backtracking(can,tar - num,i);
                path.pop_back();
            }
        }
    }
};