#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0,nums);
        return res;
    }

    void backtracking(int start,vector<int>& nums){
        res.push_back(path);
        if(start == nums.size()){
            return;
        }
        else{
            for(int i = start; i < nums.size(); i++){
                path.push_back(nums[i]);
                backtracking(i + 1,nums);
                path.pop_back();
            }
        }
    }
};