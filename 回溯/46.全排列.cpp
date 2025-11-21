#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(21,0);
        backtracking(used,nums);
        return res;
    }
    void backtracking(vector<int>& used,vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        else{
            for(int i = 0; i < nums.size();i++){
                if(!used[nums[i] + 10]){
                    used[nums[i] + 10] = 1;
                    path.push_back(nums[i]);
                    backtracking(used,nums);
                    used[nums[i] + 10] = 0;
                    path.pop_back();
                }
            }
        }
    }
};