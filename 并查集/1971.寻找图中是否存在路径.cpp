#include<LeetCodeStructs.h>
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(vector<int>& edge : edges){
            dsu.unite(edge[0], edge[1]);
        }
        return dsu.isConnected(source, destination);
    }
};