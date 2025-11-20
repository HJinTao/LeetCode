#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
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
                if(i > start && nums[i] == nums[i - 1]){
                    continue;
                }
                path.push_back(nums[i]);
                backtracking(i + 1,nums);
                path.pop_back();
            }
        }
    }
};