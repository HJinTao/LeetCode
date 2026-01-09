#include<LeetCodeStructs.h>
typedef pair<int,int> PII;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> graph(n + 1);
        for(const auto& time : times){
            int u = time[0],v = time[1],w = time[2];
            graph[u].push_back({w,v});
        }
        vector<int> dist(n + 1,INT_MAX);
        // pair[w,v]
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,u] = pq.top();  pq.pop();
            if(d > dist[u]){
                continue;
            }
            for(const auto& edge : graph[u]){
                int v = edge.second,w = edge.first;
                if(w + dist[u] < dist[v]){
                    dist[v] = w + dist[u];
                    pq.push({dist[v],v});
                }
            }
        }
        int ret = 0;
        for(int i = 1; i <= n; i++){
            ret = max(ret,dist[i]);
        }
        return ret == INT_MAX ? -1 : ret;
    }
};