#include<LeetCodeStructs.h>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int x = 0,y = col - 1;
        while(x < row && y >= 0){
            int num = matrix[x][y];
            if(num > target){
                y--;
            }
            else if(num < target){
                x++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};