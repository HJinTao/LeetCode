#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<bool> diag1,diag2,col; // 巧妙对角线转换
    vector<vector<string>> solveNQueens(int n) {
        path = vector<string>(n,string(n,'.'));
        diag1 = vector<bool>(2 * n - 1,true);
        diag2 = vector<bool>(2 * n - 1,true);
        col = vector<bool>(n,true);
        backtracking(0,n);
        return res;
    }

    void backtracking(int row,int n){
        if(row == n){
            res.push_back(path);
            return;
        }
        else{
            for(int j = 0; j < n; j++){
                if(diag1[row - j + n - 1] && diag2[j + row] && col[j]){
                    diag1[row - j + n - 1] = diag2[j + row] = col[j] = false;
                    path[row][j] = 'Q';
                    backtracking(row + 1,n);
                    diag1[row - j + n - 1] = diag2[j + row] = col[j] = true;
                    path[row][j] = '.';
                }
            }
        }
    }
};
