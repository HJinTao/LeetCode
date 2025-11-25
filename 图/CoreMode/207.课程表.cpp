#include<LeetCodeStructs.h>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grid(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(auto p : prerequisites){
            grid[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        for(int j = 0; j < numCourses; j++){
            if(!indegree[j]){
                q.push(j);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int x = q.front();q.pop();
            for(int y : grid[x]){
                indegree[y]--;
                if(!indegree[y]){
                    q.push(y);
                }
            }
        }
        return cnt == numCourses;
    }
};