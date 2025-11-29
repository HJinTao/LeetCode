#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows;i++){
            vector<int> level(i + 1,1);
            if(i >= 2){
                for(int k = 1; k < i; k++){
                    level[k] = res[i - 1][k] + res[i - 1][k - 1];
                }
            }
            res.push_back(level);
        }
        return res;
    }
};