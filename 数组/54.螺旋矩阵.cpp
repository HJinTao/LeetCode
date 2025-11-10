#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> dir = {1,0};
        vector<int> res;
        int endR = matrix.size() - 1;
        int endC = matrix[0].size() - 1;
        int start = 0;
        int visited = 1024;
        while(start <= endC && start <= endR){
            for(int j = start; j <= endC; j++){
                int& num = matrix[start][j];
                if(num != visited){
                    res.push_back(num);
                    num = visited;
                }
            }
            for(int i = start; i <= endR; i++){
                int& num = matrix[i][endC];
                if(num != visited){
                    res.push_back(num);
                    num = visited;
                }
            }
            for(int j = endC; j >= start; j--){
                int& num = matrix[endR][j];
                if(num != visited){
                    res.push_back(num);
                    num = visited;
                }
            }
            for(int i = endR; i >= start + 1; i--){
                int& num = matrix[i][start];
                if(num != visited){
                    res.push_back(num);
                    num = visited;
                }
            }
            endC--;
            endR--;
            start++;
        }
        return res;
    }
};