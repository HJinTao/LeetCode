#include<LeetCodeStructs.h>
using namespace std;
const int dir[4][2] = {0,-1,0,1,-1,0,1,0};
void dfs(vector<vector<int>>& grid,int x,int y,int row,int col){
    if(x < 0 || y < 0 || x == row || y == col || !grid[x][y]){
        return;
    }
    else{
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            dfs(grid,nx,ny,row,col);
        }
    }
}
int main(){
    int row,col;
    cin >> row >> col;
    vector<vector<int>> grid(row,vector<int>(col,0));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> grid[i][j];
        }
    }
    /*先从边缘dfs,注意遍历起始方向可选*/
    for(int i = 0; i < row; i++){
        dfs(grid,i,0,row,col);
        dfs(grid,i,col - 1,row,col);
    }
    for(int j = 0; j < col; j++){
        dfs(grid,0,j,row,col);
        dfs(grid,row - 1,j,row,col);
    }
    int res = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            res += grid[i][j];
        }
    }
    cout << res << endl;

}










