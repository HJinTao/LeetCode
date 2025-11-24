#include<LeetCodeStructs.h>
class Solution {
public:
    const int dir[4][2] = {0,-1,0,1,-1,0,1,0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // int row = grid.size();
        // int col = grid[0].size();
        // int res = 0;
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j <col; j++){
        //         if(grid[i][j] == 1){
        //             res = max(dfs(grid,i,j,row,col),res);
        //         }
        //     }
        // }
        // return res;
        return bfs(grid);
    }
    
    int dfs(vector<vector<int>>& grid,int x,int y,int row,int col){
        if(x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0){
            return 0;
        }
        else{
            int cnt = 1;
            grid[x][y] = 0;
            for(int i = 0; i < 4; i++){
                cnt += dfs(grid,x + dir[i][0],y + dir[i][1],row,col);
            }
            return cnt;
        }
    }

    int bfs(vector<vector<int>>& grid){
        int res = 0;
        int row = grid.size(),col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    int cnt = 1;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    grid[i][j] = 0;
                    while(!q.empty()){
                        int x = q.front().first,y = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nx = x + dir[k][0];
                            int ny = y + dir[k][1];
                            if(nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny]){
                                q.push(make_pair(nx,ny));
                                cnt++;
                                grid[nx][ny] = 0;
                            }
                        }
                    }
                    res = max(cnt,res);
                }
            }
        }
        return res;
    }
};