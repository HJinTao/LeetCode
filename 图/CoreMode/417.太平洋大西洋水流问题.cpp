#include<LeetCodeStructs.h>
class Solution {
public:
    int row,col;
    const int dir[4][2] = {0,-1,0,1,-1,0,1,0};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        row = heights.size();
        col = heights[0].size();
        vector<vector<bool>> v1(row,vector<bool>(col,0)),v2(row,vector<bool>(col,0));
        for(int i = 0; i < row; i++){
            dfs(heights,v1,i,0);
            dfs(heights,v2,i,col - 1);
        }
        for(int j = 0; j < col; j++){
            dfs(heights,v1,0,j);
            dfs(heights,v2,row - 1,j);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(v1[i][j] && v2[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int x,int y){
        if(visited[x][y]){
            return;
        }
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0],ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= row || ny >= col){
                continue;
            }
            int val = heights[x][y],nval = heights[nx][ny];
            if(val <= nval){
                dfs(heights,visited,nx,ny);
            }
        }
    }

    
};