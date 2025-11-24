#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int tar = graph.size() - 1;
        path.push_back(0);
        dfs(graph,0,tar);
        return res;
    }

    void dfs(const vector<vector<int>> &graph,int x,int tar){
        if(x == tar){
            res.push_back(path);
            return;
        }
        else{
            for(const int i : graph[x]){
                path.push_back(i);
                dfs(graph,i,tar);
                path.pop_back();
            }
        }
    }
};