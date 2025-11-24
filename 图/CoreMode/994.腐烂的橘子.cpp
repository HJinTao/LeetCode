#include<LeetCodeStructs.h>
class Solution {
public:
    int dir[4][2] = {0,-1,0,1,-1,0,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int row = grid.size(),col = grid[0].size();
        int frech = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j] == 1){
                    frech++;
                }
            }
        }
        if(!frech){
            return 0;
        }
        int res = -1;
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int k = 0; k < size; k++){
                int x = q.front().first,y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        frech--;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        return frech ? -1 : res;
    }
};