#include<LeetCodeStructs.h>
class Solution {
public:
    int dir[4][2] = {0,-1,0,1,-1,0,1,0};
    int numIslands(vector<vector<char>>& grid) {
        int xm = grid.size();
        int ym = grid[0].size();
        int res = 0;
        for(int i = 0; i < xm;i++){
            for(int j = 0; j < ym;j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid,i,j,xm,ym);
                }
            }
        }
        return res;
        
    }

    void dfs(vector<vector<char>>& grid,int x,int y,int xm,int ym){
        if(x < 0 || x >= xm || y < 0 || y >= ym || grid[x][y] == '0'){
            return;
        }
        else{
            grid[x][y] = '0';
            for(int i = 0 ; i < 4; i++){
                dfs(grid,x + dir[i][0],y + dir[i][1],xm,ym);
            }
        }
    }

    void bfs(vector<vector<char>>& grid,int x,int y,int xm,int ym){
        queue<pair<int,int>> q;
        grid[x][y] = '0';
        q.push(make_pair(x,y));
        int nx,ny;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                nx = x + dir[i][0];
                ny = y + dir[i][1];
                if(nx >= 0 && nx < xm && ny >= 0 && ny < ym && grid[nx][ny] == '1'){
                    grid[nx][ny] = '0';
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
};