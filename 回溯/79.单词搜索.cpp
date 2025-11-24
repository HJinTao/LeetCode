#include<LeetCodeStructs.h>
class Solution {
public:
    int dir[4][2] = {0,-1,0,1,-1,0,1,0};
    int row,col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word.front()){
                    if(dfs(board,word,0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board,const string& word,int index,int x,int y){
        if(board[x][y] == '#'){
            return false;
        }
        else if(index == word.size() - 1){
            return true;
        }
        else{
            char temp = board[x][y];
            board[x][y] = '#';
            index++;
            bool check = false;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] == word[index]){
                    check |= dfs(board,word,index,nx,ny);
                }
            }
            board[x][y] = temp;   //注意回溯时一定要恢复状态
            index--;
            return check;
        }
    }
};