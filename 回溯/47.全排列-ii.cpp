#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
            vector<int> hash(21,0);
            for(int i = 0; i < nums.size();i++){
                int key = nums[i] + 10;
                if(!used[i] && !hash[key]){    // used用index作为hash key,不然会出现哈希冲突
                    hash[key] = 1;
                    used[i] = 1;
                    path.push_back(nums[i]);
                    backtracking(used,nums);
                    used[i] = 0;
                    path.pop_back();
                }
            }
        }
    }
};