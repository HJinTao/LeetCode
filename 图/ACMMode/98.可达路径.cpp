#include <LeetCodeStructs.h>
using namespace std;

vector<int> path;
vector<vector<int>> res;
void dfs(const vector<vector<int>>& graph, int x, int n) {
    if (x == n) {
        res.push_back(path);
        return;
    } 
    else {
        for (int i = 1; i <= n; i++) {
            if (graph[x][i]) {
                path.push_back(i);
                dfs(graph, i, n);
                path.pop_back();
            }
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        graph[s][t] = 1;
    }
    path.push_back(1);
    dfs(graph,1,N);
    for(const auto& p: res){
        for(int i = 0; i < p.size() - 1;i++){
            cout << p[i] << ' ';
        }
        cout << p.back();
        cout << endl;
    }
    if(res.empty()){
        cout << -1 << endl;
    }
    return 0;
}
