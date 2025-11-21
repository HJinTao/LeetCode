#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(0,nums);
        return res;
    }

    void backtracking(int start,vector<int>& nums){
        if(path.size() >= 2){
            res.push_back(path);
        }
        if(start == nums.size()){
            return;
        }
        else{
            int hash[201]{0};
            for(int i = start; i < nums.size(); i++){
                if(path.empty() || path.back() <= nums[i]){
                    if(hash[nums[i] + 100]){
                        continue;
                    }
                    hash[nums[i] + 100] = 1;
                    path.push_back(nums[i]);
                    backtracking(i + 1,nums);
                    path.pop_back();
                }
            }
        }
    }
};

