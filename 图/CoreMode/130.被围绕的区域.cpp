#include<LeetCodeStructs.h>
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<void(int i, int j)> dfs = [&](int i, int j){
            visited[i][j] = true;
            board[i][j] = '#';
            for(int d = 0; d < 4; d++){
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O' && !visited[ni][nj]){
                    dfs(ni, nj);
                }
            }
        };


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' &&(i == 0 || i == m - 1 || j == 0 || j == n - 1)){
                    dfs(i, j);
                }
            }
        }

        for(auto& row : board){
            for(char& ch : row){
                if(ch == '#'){
                    ch = 'O';
                }
                else if(ch == 'O'){
                    ch = 'X';
                }
            }
        }
    }
};