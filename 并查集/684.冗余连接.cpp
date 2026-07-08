#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1); //edges的编号从1开始
        for(auto& e : edges){
            int x = e[0], y = e[1];
            if(dsu.find(x) != dsu.find(y)){
                dsu.unite(x, y);
            }
            else{
                return e;
            }
        }
        return {};
    }
};