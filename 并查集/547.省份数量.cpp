#include<LeetCodeStructs.h>
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isConnected[i][j]){
                    dsu.unite(i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(dsu.parent[i] == i){
                res++;
            }
        }
        return res;
    }
};