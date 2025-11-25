#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> res;
        vector<vector<int>> grid(n);
        vector<int> in(n,0);
        queue<int> q;
        for(const auto& p : pre){
            grid[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        for(int i = 0; i < n; i++){
            if(!in[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();  q.pop();
            res.push_back(x);
            for(const int &y : grid[x]){
                in[y]--;
                if(!in[y]){
                    q.push(y);
                }
            }
        }
        return res.size() == n ? res : vector<int>();
    }
};